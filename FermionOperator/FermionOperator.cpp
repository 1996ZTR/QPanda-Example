#include "QPanda.h"
USING_QPANDA

int main()
{
	QPanda::FermionOperator a("0 1+", 2);
	QPanda::FermionOperator b("2+ 3", 3);

	auto plus = a + b;
	auto minus = a - b;
	auto muliply = a * b;

	std::cout << "a + b = " << plus << std::endl << std::endl;
	std::cout << "a - b = " << minus << std::endl << std::endl;
	std::cout << "a * b = " << muliply << std::endl << std::endl;

	std::cout << "normal_ordered(a + b) = " << plus.normal_ordered() << std::endl << std::endl;
	std::cout << "normal_ordered(a - b) = " << minus.normal_ordered() << std::endl << std::endl;
	std::cout << "normal_ordered(a * b) = " << muliply.normal_ordered() << std::endl << std::endl;

	return 0;
}

