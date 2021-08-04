#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto q = qvm->qAllocMany(2);
	auto c = qvm->cAllocMany(2);

	// 构建量子线路
	QCircuit cir;
	cir << H(q[1])
		<< CNOT(q[0], q[1])
		<< H(q[1]);

	// 获取线路对应矩阵
	QStat cir_matrix = getCircuitMatrix(cir);

	// 打印矩阵信息
	std::cout << cir_matrix << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}
