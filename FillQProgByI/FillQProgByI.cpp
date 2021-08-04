#include "QPanda.h"
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto q = qvm->qAllocMany(4);
	auto c = qvm->cAllocMany(4);

	QCircuit cir;
	QProg prog;

	// �������ӳ���
	cir << CNOT(q[2], q[3])
		<< CU(1, 2, 3, 4, q[1], q[0])
		<< (H(q[1]))
		<< X(q[2])
		<< RZ(q[1], PI / 2)
		<< Y(q[2])
		<< (CR(q[0], q[3], PI / 2))
		<< (S(q[2]))
		<< S(q[1])
		<< RZ(q[1], PI / 2)
		<< Y(q[0])
		<< SWAP(q[3], q[1]);

	prog << cir << MeasureAll(q, c);

	// ���ԭ���ӳ���
	std::cout << "The source QProg:" << std::endl;
	std::cout << prog << std::endl;

	// ���ӳ������ I ��
	auto filled_prog = fill_qprog_by_I(prog);

	// ������ I �ŵ����ӳ���
	std::cout << "The filled QProg:" << std::endl;
	std::cout << filled_prog << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}

