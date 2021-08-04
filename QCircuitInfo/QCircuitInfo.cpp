#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto q = qvm->qAllocMany(2);
	auto c = qvm->cAllocMany(2);

	// ����������·
	QCircuit cir;
	cir << H(q[1])
		<< CNOT(q[0], q[1])
		<< H(q[1]);

	// ��ȡ��·��Ӧ����
	QStat cir_matrix = getCircuitMatrix(cir);

	// ��ӡ������Ϣ
	std::cout << cir_matrix << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}
