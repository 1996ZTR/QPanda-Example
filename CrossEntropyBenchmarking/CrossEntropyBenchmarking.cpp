#include "QPanda.h"
USING_QPANDA
using namespace std;
int main()
{
	// �������������
	auto qvm = new NoiseQVM();
	qvm->init();

	// ͬ�����������Ƽ��������������ʵоƬ��
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	auto qv = qvm->qAllocMany(4);

	// ������������
	std::vector<QVec> qvs = { { qv[0], qv[1] } };
	qvm->set_noise_model(DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.1, qvs);

	// ���ò�ͬ�������
	std::vector<int> range = { 2,4,6,8,10 };
	auto res = double_gate_xeb(qvm, qv[0], qv[1], range, 10, 1000, CZ_GATE);

	// ��Ӧ����ֵ������Ӱ�죬������ֵԽ�����ý��ԽС���Ҳ������࣬�����ֵԽС��
	for (auto it : res)
	{
		std::cout << it.first << "  :  " << it.second << std::endl;
	}
	qvm->finalize();
	delete qvm;
	system("pause");
	return 0;
}

