#include "QPanda.h"
USING_QPANDA

int main()
{


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
	vqc.insert(VQG_RZ(q[0], 0.123));
	vqc.insert(VQG_CZ(q[0], q[1]));
	vqc.insert(VQG_CNOT(q[0], q[1]));

	QCircuit circuit = vqc.feed();
	QProg prog;
	prog << circuit;

	std::cout << convert_qprog_to_originir(prog, machine) << std::endl << std::endl;

	m1(0, 0) = 3;
	m2(0, 0) = 4;

	x.setValue(m1);
	y.setValue(m2);

	QCircuit circuit2 = vqc.feed();
	QProg prog2;
	prog2 << circuit2;

	std::cout << convert_qprog_to_originir(prog2, machine) << std::endl;

	return 0;
}


