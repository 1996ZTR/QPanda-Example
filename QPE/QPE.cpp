#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine(CPU);
	// 申请寄存器并初始化
	QVec qvec = qvm->qAllocMany(1);
	QVec cqv = qvm->qAllocMany(2);

	// 提取特征值相位并合并到基向量
	auto prog = createEmptyQProg();
	prog << H(cqv[0]) << H(cqv[1]);
	prog << S(qvec[0]);
	prog << RY(qvec[0], PI / 4).control(cqv[1]);
	prog << RY(qvec[0], PI / 4).control(cqv[0]);
	prog << RY(qvec[0], PI / 4).control(cqv[0]);
	prog << QFT(cqv).dagger();

	// 以概率方法输出结果量子态的理论值（并非测量）
	auto result = probRunDict(prog, cqv);
	destroyQuantumMachine(qvm);

	// 输出结果
	for (auto aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	return 0;
}

