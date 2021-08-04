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

	// �������ӳ���
	srcprog << CNOT(q[0], q[3])
		<< CNOT(q[0], q[2])
		<< CNOT(q[1], q[3])
		<< CZ(q[1], q[2])
		<< CZ(q[0], q[2])
		<< T(q[1])
		<< S(q[2])
		<< H(q[3]);

	// ��srcprog���и��ʲ������õ����r1
	qvm->directlyRun(srcprog);
	auto r1 = qvm->pMeasureNoIndex(q);

	// ��srcprog��������ƥ�䣬�õ�ƥ��ORIGIN_VIRTUAL_ARCH���˽ṹ�����ӳ���outprog
	QProg  outprog = topology_match(srcprog, q, qvm, CNOT_GATE_METHOD, ORIGIN_VIRTUAL_ARCH);

	// ��outprog���и��ʲ������õ����r2
	qvm->directlyRun(outprog);
	auto r2 = qvm->pMeasureNoIndex(q);

	// �Աȸ��ʲ������r1��r2
	int size = min(r1.size(), r2.size());
	bool result_equal = true;
	for (int i = 0; i < size; i++)
	{
		if ((fabs(r1[i] - r2[i]) > 1e-6))
			result_equal = false;
	}

	// ��������ͬ����ӡ���
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

