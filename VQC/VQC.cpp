#include "QPanda.h"
USING_QPANDA

int main()
{
	using namespace std;
	using namespace QPanda::Variational;

	constexpr int qnum = 2;

	QuantumMachine *machine = initQuantumMachine(CPU);
	auto q = machine->qAllocMany(qnum);

	MatrixXd m1(1, 1);
	MatrixXd m2(1, 1);
	m1(0, 0) = 1;
	m2(0, 0) = 2;

	var x(m1);
	var y(m2);

	VQC vqc;
	vqc.insert(VQG_H(q[0]));
	vqc.insert(VQG_RX(q[0], x));
	vqc.insert(VQG_RY(q[1], y));

	QCircuit circuit = vqc.feed();
	QProg prog;
	prog << circuit;

	std::cout << convert_qprog_to_originir(prog, machine) << std::endl << std::endl;

	auto gates = vqc.get_var_in_which_gate(x);

	int pos = shared_ptr<VariationalQuantumGate>(gates[0])->var_pos(x);

	vector<tuple<weak_ptr<VariationalQuantumGate>, size_t, double>> plus;
	plus.push_back(make_tuple(gates[0], pos, 3));

	QCircuit circuit2 = vqc.feed(plus);
	QProg prog2;
	prog2 << circuit2;

	std::cout << convert_qprog_to_originir(prog2, machine) << std::endl;

	return 0;
}

