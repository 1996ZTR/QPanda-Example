#include "QPanda.h"
#include <fstream>

using namespace std;
using namespace QPanda;
using namespace QPanda::Variational;

VQC parity_check_circuit(QVec &qubit_vec)
{
	VQC circuit;
	for (auto i = 0; i < qubit_vec.size() - 1; i++)
	{
		circuit.insert(VQG_CNOT(
			qubit_vec[i],
			qubit_vec[qubit_vec.size() - 1]));
	}

	return circuit;
}

VQC simulateZTerm(
	QVec &qubit_vec,
	var coef,
	var t)
{
	VQC circuit;
	if (0 == qubit_vec.size())
	{
		return circuit;
	}
	else if (1 == qubit_vec.size())
	{
		circuit.insert(VQG_RZ(qubit_vec[0], coef * t*-1));
	}
	else
	{
		circuit.insert(parity_check_circuit(qubit_vec));
		circuit.insert(VQG_RZ(qubit_vec[qubit_vec.size() - 1], coef * t*-1));
		circuit.insert(parity_check_circuit(qubit_vec));
	}

	return circuit;
}

VQC simulatePauliZHamiltonian(
	QVec& qubit_vec,
	const QPanda::QHamiltonian & hamiltonian,
	var t)
{
	VQC circuit;

	for (auto j = 0; j < hamiltonian.size(); j++)
	{
		QVec tmp_vec;
		auto item = hamiltonian[j];
		auto map = item.first;

		for (auto iter = map.begin(); iter != map.end(); iter++)
		{
			if ('Z' != iter->second)
			{
				QCERR("Bad pauliZ Hamiltonian");
				throw std::string("Bad pauliZ Hamiltonian.");
			}

			tmp_vec.push_back(qubit_vec[iter->first]);
		}

		if (!tmp_vec.empty())
		{
			circuit.insert(simulateZTerm(tmp_vec, item.second, t));
		}
	}

	return circuit;
}

PauliOperator getHamiltonian()
{
	PauliOperator::PauliMap pauli_map{
		{"Z0 Z4", 0.73},{"Z2 Z5", 0.88},
		{"Z0 Z5", 0.33},{"Z2 Z6", 0.58},
		{"Z0 Z6", 0.50},{"Z3 Z5", 0.67},
		{"Z1 Z4", 0.69},{"Z3 Z6", 0.43},
		{"Z1 Z5", 0.36}
	};

	return PauliOperator(pauli_map);
}

int main()
{
	PauliOperator op = getHamiltonian();

	QuantumMachine *machine = initQuantumMachine();
	QVec qlist;
	for (int i = 0; i < op.getMaxIndex(); ++i)
		qlist.push_back(machine->qAlloc());

	VQC vqc;
	for_each(qlist.begin(), qlist.end(), [&vqc](Qubit* qbit)
	{
		vqc.insert(VQG_H(qbit));
	});

	int qaoa_step = 4;

	var x(MatrixXd::Random(2 * qaoa_step, 1), true);

	for (auto i = 0u; i < 2 * qaoa_step; i += 2)
	{
		vqc.insert(simulatePauliZHamiltonian(qlist, op.toHamiltonian(), x[i + 1]));
		for (auto _q : qlist) {
			vqc.insert(VQG_RX(_q, x[i]));
		}
	}

	var loss = qop(vqc, op, machine, qlist);
	auto optimizer = MomentumOptimizer::minimize(loss, 0.02, 0.9);

	auto leaves = optimizer->get_variables();
	constexpr size_t iterations = 100;
	for (auto i = 0u; i < iterations; i++)
	{
		optimizer->run(leaves);
		std::cout << " iter: " << i << " loss : " << optimizer->get_loss() << std::endl;
	}

	QProg prog;
	QCircuit circuit = vqc.feed();
	prog << circuit;

	directlyRun(prog);
	auto result = quickMeasure(qlist, 100);

	for (auto i : result)
	{
		std::cout << i.first << " : " << i.second << " ";
	}

	return 0;
}


