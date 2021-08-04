#include "QPanda.h"
USING_QPANDA
int main()
{
	// 构建噪声虚拟机，以及设置参数
	auto qvm = new NoiseQVM();
	qvm->init();
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.005);
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, PAULI_Y_GATE, 0.005);

	// 同样可以申请云计算机器（采用真实芯片）
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	auto qv = qvm->qAllocMany(4);

	// 设置随机线路中clifford门集数量
	std::vector<int > range = { 5,10,15 };

	// 测量单比特随机基准
	std::map<int, double> res = single_qubit_rb(qvm, qv[0], range, 10, 1000);

	// 同样可以测量两比特随机基准
	//std::map<int, double> res = double_qubit_rb(qvm, qv[0], qv[1], range, 10, 1000);

	// 对应的数值随噪声影响，噪声数值越大，所得结果越小，且随clifford门集数量增多，结果数值越小。
	for (auto it : res)
	{
		std::cout << it.first << "  :  " << it.second << std::endl;
	}

	qvm->finalize();
	delete qvm;
	return 0;
}

