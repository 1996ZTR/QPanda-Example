#include "QPanda.h"
USING_QPANDA
using namespace std;
int main()
{
	// 创建噪声虚拟机
	auto qvm = new NoiseQVM();
	qvm->init();

	// 同样可以申请云计算机器（采用真实芯片）
	//auto qvm = new QCloudMachine();
	//qvm->init("898D47CF515A48CEAA9F2326394B85C6")

	auto qv = qvm->qAllocMany(4);

	// 设置噪声参数
	std::vector<QVec> qvs = { { qv[0], qv[1] } };
	qvm->set_noise_model(DEPOLARIZING_KRAUS_OPERATOR, CZ_GATE, 0.1, qvs);

	// 设置不同层数组合
	std::vector<int> range = { 2,4,6,8,10 };
	auto res = double_gate_xeb(qvm, qv[0], qv[1], range, 10, 1000, CZ_GATE);

	// 对应的数值随噪声影响，噪声数值越大，所得结果越小，且层数增多，结果数值越小。
	for (auto it : res)
	{
		std::cout << it.first << "  :  " << it.second << std::endl;
	}
	qvm->finalize();
	delete qvm;
	system("pause");
	return 0;
}

