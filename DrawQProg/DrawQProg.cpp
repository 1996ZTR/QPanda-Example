#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto q = qvm->qAllocMany(3);
	auto c = qvm->cAllocMany(3);
	QProg prog;
	QCircuit cir1, cir2;

	// 构建量子程序
	auto gate = S(q[1]);
	gate.setDagger(true);
	cir1 << H(q[0]) << S(q[2]) << CNOT(q[0], q[1]) << CZ(q[1], q[2]) << gate;
	cir1.setDagger(true);
	cir2 << cir1 << CU(1, 2, 3, 4, q[0], q[2]) << S(q[2]) << CR(q[2], q[1], PI / 2);
	cir2.setDagger(true);
	prog << cir2 << MeasureAll(q, c);

	// 量子程序字符画
	std::string text_picture = draw_qprog(prog);

	// 打印字符画
	std::cout << text_picture << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}

