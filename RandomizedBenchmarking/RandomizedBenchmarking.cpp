#include "QPanda.h"
USING_QPANDA
int main()
{
	// ����������������Լ����ò���
	auto qvm = new NoiseQVM();
	qvm->init();
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.005);
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, PAULI_Y_GATE, 0.005);

	// ͬ�����������Ƽ��������������ʵоƬ��
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	auto qv = qvm->qAllocMany(4);

	// ���������·��clifford�ż�����
	std::vector<int > range = { 5,10,15 };

	// ���������������׼
	std::map<int, double> res = single_qubit_rb(qvm, qv[0], range, 10, 1000);

	// ͬ�����Բ��������������׼
	//std::map<int, double> res = double_qubit_rb(qvm, qv[0], qv[1], range, 10, 1000);

	// ��Ӧ����ֵ������Ӱ�죬������ֵԽ�����ý��ԽС������clifford�ż��������࣬�����ֵԽС��
	for (auto it : res)
	{
		std::cout << it.first << "  :  " << it.second << std::endl;
	}

	qvm->finalize();
	delete qvm;
	return 0;
}

