#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine();
	auto q = qvm->qAllocMany(5);
	auto c = qvm->cAllocMany(5);

	QProg prog;
	QCircuit replace_cir, query_cir;

	// 构建量子程序
	prog << H(q[0])
		<< H(q[2])
		<< H(q[3])
		<< CNOT(q[1], q[0])
		<< H(q[0])
		<< CNOT(q[1], q[2])
		<< H(q[2])
		<< CNOT(q[2], q[3])
		<< H(q[3]);

	std::cout << "查询替换前：" << std::endl;
	std::cout << convert_qprog_to_originir(prog, qvm) << std::endl;

	// 构建查询线路、 构建替换线路
	query_cir << H(q[0]) << CNOT(q[1], q[0]) << H(q[0]);
	replace_cir << CZ(q[0], q[1]);
	const std::vector<std::pair<QCircuit, QCircuit>>  replace_cir_vec = { {query_cir, replace_cir} };

	// 搜索量子程序中的查询线路，并用替换线路替代,但会改变原来prog的结构
	sub_cir_replace(prog, replace_cir_vec);

	std::cout << std::endl;
	std::cout << "查询替换后：" << std::endl;
	std::cout << convert_qprog_to_originir(prog, qvm) << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}
