#include "QPanda.h"
USING_QPANDA
int main()
{
	// ���������������������������
	auto qvm = new NoiseQVM();
	qvm->init();
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.005);

	// ͬ�����������Ƽ��������������ʵоƬ����������ʵоƬҪ����оƬ����
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	// ���������������ӱ�����ϣ� ����������Ϊ2�飬���� ���ӱ���3��4Ϊһ�飻���ӱ���2��3��5Ϊһ��
	std::vector <std::vector<int> >qubit_lists = { {3,4}, {2,3,5} };

	// ���������������
	int ntrials = 100;

	// ���ò�������,����ʵоƬ�������������shots��ֵ
	int shots = 4000;

	// �����������
	auto qv_result = calculate_quantum_volume(qvm, qubit_lists, ntrials, shots);

	// ���������������������ֵ�����������ֵ��С���ܵ�Ӱ�죬����Խ��qv��ֵԽС��
	std::cout << "Quantum Volume : " << qv_result << std::endl;

	qvm->finalize();
	delete qvm;
	return 0;
}

