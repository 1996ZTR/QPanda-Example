#include "QPanda.h"
USING_QPANDA

int main()
{
	// 单量子门有效性验证
	std::vector<std::string> single_gate;
	std::vector<std::string> valid_single_gate; // 有效的量子逻辑门组合会输出到这个容器中
	single_gate.push_back("T");
	single_gate.push_back("H");
	single_gate.push_back("S");

	// 得到有效的量子逻辑门组合，和有效组合的类型
	auto single_gate_type = validateSingleQGateType(single_gate, valid_single_gate);

	std::cout << "SingleGateTransferType: " << single_gate_type << std::endl;
	for (auto &val : valid_single_gate)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// 双量子门有效性验证
	std::vector<std::string> double_gate;
	std::vector<std::string> valid_double_gate; // 有效的量子逻辑门组合会输出到这个容器中
	double_gate.push_back("CNOT");
	double_gate.push_back("SWAP");
	double_gate.push_back("CZ");

	// 得到有效的量子逻辑门组合，和有效组合的类型
	auto double_gate_type = validateDoubleQGateType(double_gate, valid_double_gate);

	std::cout << "doubleGateTransferType: " << double_gate_type << std::endl;
	for (auto &val : valid_double_gate)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	return 0;
}