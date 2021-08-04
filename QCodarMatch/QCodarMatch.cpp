#include "QPanda.h"
using namespace std;
using namespace QPanda;
int  main()
{
	auto qvm = new CPUQVM();
	qvm->init();
	auto q = qvm->qAllocMany(8);
	auto c = qvm->cAllocMany(8);
	auto srcprog = QProg();

	// 构建量子程序
	srcprog << CNOT(q[0], q[3])
		<< CNOT(q[0], q[2])
		<< CNOT(q[1], q[3])
		<< CZ(q[1], q[2])
		<< CZ(q[0], q[2])
		<< T(q[1])
		<< S(q[2])
		<< H(q[3]);

	// 对srcprog进行概率测量，得到结果r1
	qvm->directlyRun(srcprog);
	auto r1 = qvm->pMeasureNoIndex(q);

	// 对srcprog进行拓扑匹配，得到匹配ORIGIN_VIRTUAL_ARCH拓扑结构的量子程序outprog
	QProg  outprog = topology_match(srcprog, q, qvm, CNOT_GATE_METHOD, ORIGIN_VIRTUAL_ARCH);

	// 对outprog进行概率测量，得到结果r2
	qvm->directlyRun(outprog);
	auto r2 = qvm->pMeasureNoIndex(q);

	// 对比概率测量结果r1和r2
	int size = min(r1.size(), r2.size());
	bool result_equal = true;
	for (int i = 0; i < size; i++)
	{
		if ((fabs(r1[i] - r2[i]) > 1e-6))
			result_equal = false;
	}

	// 如果结果相同，打印结果
	if (result_equal == true)
	{
		std::cout << "The probability measurements are the same, prob list:  " << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << r1[i] << std::endl;
		}
	}

	qvm->finalize();
	delete qvm;
	return 0;
}

