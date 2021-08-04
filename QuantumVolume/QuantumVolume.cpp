#include "QPanda.h"
USING_QPANDA
int main()
{
	// 构建噪声虚拟机，设置噪声参数
	auto qvm = new NoiseQVM();
	qvm->init();
	qvm->set_noise_model(NOISE_MODEL::DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.005);

	// 同样可以申请云计算机器（采用真实芯片），采用真实芯片要考虑芯片构造
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	// 构建待测量的量子比特组合， 这里比特组合为2组，其中 量子比特3、4为一组；量子比特2，3，5为一组
	std::vector <std::vector<int> >qubit_lists = { {3,4}, {2,3,5} };

	// 设置随机迭代次数
	int ntrials = 100;

	// 设置测量次数,即真实芯片或者噪声虚拟机shots数值
	int shots = 4000;

	// 测量量子体积
	auto qv_result = calculate_quantum_volume(qvm, qubit_lists, ntrials, shots);

	// 调整噪声虚拟机参数，数值会根据噪声数值大小而受到影响，噪声越大，qv数值越小。
	std::cout << "Quantum Volume : " << qv_result << std::endl;

	qvm->finalize();
	delete qvm;
	return 0;
}

