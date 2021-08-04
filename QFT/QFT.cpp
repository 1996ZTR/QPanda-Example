#include "QPanda.h"
using namespace QPanda;

int main()
{
	auto qvm = initQuantumMachine(CPU);
	// ����Ĵ�������ʼ��
	QVec qvec = qvm->qAllocMany(3);

	// ����QFT����
	auto prog = createEmptyQProg();
	prog << QFT(qvec);

	// �Ը��ʷ�������������̬������ֵ�����ǲ�����
	directlyRun(prog);
	auto result = probRunTupleList(prog, qvec);
	destroyQuantumMachine(qvm);

	// ������
	for (auto aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	return 0;
}

