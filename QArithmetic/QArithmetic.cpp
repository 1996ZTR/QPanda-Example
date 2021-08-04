#include "QPanda.h"
using namespace QPanda;

int main()
{
	auto qvm = initQuantumMachine();

	// 为了节约比特数，辅助比特有大量互相借用
	QVec qdivvec = qvm->qAllocMany(10);
	QVec qmulvec = { qdivvec[0],qdivvec[1],qdivvec[2],qdivvec[3],
	   qdivvec[4],qdivvec[5],qdivvec[9] };
	QVec qsubvec = { qmulvec[0],qmulvec[1],qmulvec[2],qmulvec[3],
	   qmulvec[4],qmulvec[5] };
	QVec qvec1 = qvm->qAllocMany(4);
	QVec qvec2 = qvm->qAllocMany(4);
	QVec qvec3 = qvm->qAllocMany(4);
	auto cbit = qvm->cAlloc();
	auto qcProg = CreateEmptyQProg();

	// 4/1=4
	qcProg << bind_data(4, qvec3);
	qcProg << bind_data(1, qvec2);
	qcProg << QDivider(qvec3, qvec2, qvec1, qdivvec, cbit);
	qcProg << bind_data(1, qvec2);

	// 4+1=5
	qcProg << bind_data(1, qvec2);
	qcProg << QAdd(qvec1, qvec2, qsubvec);
	qcProg << bind_data(1, qvec2);

	// 5-3=2
	qcProg << bind_data(3, qvec2);
	qcProg << QSub(qvec1, qvec2, qsubvec);
	qcProg << bind_data(3, qvec2);

	// 2*5=10
	qcProg << bind_data(5, qvec2);
	qcProg << QMul(qvec1, qvec2, qvec3, qmulvec);
	qcProg << bind_data(5, qvec2);

	auto result = probRunDict(qcProg, qmulvec);
	destroyQuantumMachine(qvm);

	for (auto aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	return 0;
}

