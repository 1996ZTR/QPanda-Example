#include "QPanda.h"
USING_QPANDA

int main()
{
	auto machine = initQuantumMachine(CPU);
	auto x = machine->allocateCBit();
	std::vector<SearchDataByUInt> search_space;
	search_space.push_back(8);
	search_space.push_back(7);
	search_space.push_back(6);
	search_space.push_back(0);

	QVec measure_qubits;
	QProg grover_Qprog = build_grover_alg_prog(search_space, x == 6, machine, measure_qubits, 1);

	//measure
	std::cout<<"Strat pmeasure."<<std::endl;
	auto result = probRunDict(grover_Qprog, measure_qubits);

	std::cout << "pmeasure result"<<std::endl;
	for (auto aiter : result)
	{
		if (0 == aiter.second)
		{
			continue;
		}
		printf("%s:%5f\n", aiter.first.c_str(), aiter.second);
	}

	destroyQuantumMachine(machine);

	return 0;
}

