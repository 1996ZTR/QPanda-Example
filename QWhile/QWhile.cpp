#include "QPanda.h"
USING_QPANDA

int main()
{
	init();
	QProg prog;
	auto qvec = qAllocMany(3);
	auto cvec = cAllocMany(3);
	cvec[0].set_val(0);

	// ����QWhile��ѭ����֧
	QProg prog_in;
	prog_in << BARRIER(qvec) << cvec[0] << H(qvec[cvec[0]])
		<< (cvec[0] = cvec[0] + 1);

	// ����QWhile
	auto qwhile = createWhileProg(cvec[0] < 3, prog_in);

	// QWhile���뵽���ӳ�����
	prog << qwhile;

	// ���ʲ�����������Ŀ�����ӱ��صĸ��ʲ�����������Ӧ���±�Ϊʮ����
	auto result = probRunTupleList(prog, qvec);

	// ��ӡ�������
	for (auto & val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}

