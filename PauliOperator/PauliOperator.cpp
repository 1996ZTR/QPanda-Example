#include "QPanda.h"
USING_QPANDA
int main()
{
	QPanda::PauliOperator a("Z0 Z1", 2);
	QPanda::PauliOperator b("X5 Y6", 3);

	auto plus = a + b;
	auto minus = a - b;
	auto muliply = a * b;

	std::cout << "a + b = " << plus << std::endl << std::endl;
	std::cout << "a - b = " << minus << std::endl << std::endl;
	std::cout << "a * b = " << muliply << std::endl << std::endl;

	std::cout << "Index : " << muliply.getMaxIndex() << std::endl << std::endl;

	std::map<size_t, size_t> index_map;
	auto remap_pauli = muliply.remapQubitIndex(index_map);

	std::cout << "remap_pauli : " << remap_pauli << std::endl << std::endl;
	std::cout << "Index : " << remap_pauli.getMaxIndex() << std::endl;

	return 0;
}

