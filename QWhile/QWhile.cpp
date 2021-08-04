#include "QPanda.h"
USING_QPANDA

int main()
{
	init();
	QProg prog;
	auto qvec = qAllocMany(3);
	auto cvec = cAllocMany(3);
	cvec[0].set_val(0);

	// 构建QWhile的循环分支
	QProg prog_in;
	prog_in << BARRIER(qvec) << cvec[0] << H(qvec[cvec[0]])
		<< (cvec[0] = cvec[0] + 1);

	// 构建QWhile
	auto qwhile = createWhileProg(cvec[0] < 3, prog_in);

	// QWhile插入到量子程序中
	prog << qwhile;

	// 概率测量，并返回目标量子比特的概率测量结果，其对应的下标为十进制
	auto result = probRunTupleList(prog, qvec);

	// 打印测量结果
	for (auto & val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}

