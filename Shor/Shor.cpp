#include "QPanda.h"
USING_QPANDA

int main()
{
	int N = 15;
	auto p = Shor_factorization(N);
	std::cout << p.first << "," << p.second.first << "," << p.second.second << std::endl;

	return 0;
}
