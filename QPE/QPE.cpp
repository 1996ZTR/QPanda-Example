#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine(CPU);
	// ����Ĵ�������ʼ��
	QVec qvec = qvm->qAllocMany(1);
	QVec cqv = qvm->qAllocMany(2);

	// ��ȡ����ֵ��λ���ϲ���������
	auto prog = createEmptyQProg();
	prog << H(cqv[0]) << H(cqv[1]);
	prog << S(qvec[0]);
	prog << RY(qvec[0], PI / 4).control(cqv[1]);
	prog << RY(qvec[0], PI / 4).control(cqv[0]);
	prog << RY(qvec[0], PI / 4).control(cqv[0]);
	prog << QFT(cqv).dagger();

	// �Ը��ʷ�������������̬������ֵ�����ǲ�����
	auto result = probRunDict(prog, cqv);
	destroyQuantumMachine(qvm);

	// ������
	for (auto aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	return 0;
}

