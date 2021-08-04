#include "QPanda.h"
using namespace QPanda;

int main()
{
	auto qvm = initQuantumMachine(CPU);
	// 申请寄存器并初始化
	QVec qvec = qvm->qAllocMany(3);

	// 调用QFT函数
	auto prog = createEmptyQProg();
	prog << QFT(qvec);

	// 以概率方法输出结果量子态的理论值（并非测量）
	directlyRun(prog);
	auto result = probRunTupleList(prog, qvec);
	destroyQuantumMachine(qvm);

	// 输出结果
	for (auto aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	return 0;
}

