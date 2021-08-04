#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = new CPUQVM();
	qvm->init();
	auto q = qvm->qAllocMany(2);

	QStat source_matrix =
	{
		qcomplex_t(0.6477054522122977, 0.1195417767870219),qcomplex_t(-0.16162176706189357, -0.4020495632468249),qcomplex_t(-0.19991615329121998, -0.3764618308248643),qcomplex_t(-0.2599957197928922, -0.35935248873007863),
		qcomplex_t(-0.16162176706189363, -0.40204956324682495),qcomplex_t(0.7303014482204584, -0.4215172444390785),qcomplex_t(-0.15199187936216693, 0.09733585496768032),qcomplex_t(-0.22248203136345918, -0.1383600597660744),
		qcomplex_t(-0.19991615329122003 , -0.3764618308248644),qcomplex_t(-0.15199187936216688, 0.09733585496768032),qcomplex_t(0.6826630277354306, -0.37517063774206166),qcomplex_t(-0.3078966462928956, -0.2900897445133085),
		qcomplex_t(-0.2599957197928923, -0.3593524887300787),qcomplex_t(-0.22248203136345912, -0.1383600597660744),qcomplex_t(-0.30789664629289554, -0.2900897445133085),qcomplex_t(0.6640994547408099, -0.338593803336005)
	};

	std::cout << "source matrix:" << std::endl << source_matrix << std::endl;

	QCircuit out_cir = matrix_decompose_qr(q, source_matrix);
	auto circuit_matrix = getCircuitMatrix(out_cir);

	std::cout << "the decomposed matrix:" << std::endl << circuit_matrix << std::endl;

	if (!mat_compare(source_matrix, circuit_matrix, 0.000001))
	{
		std::cout << "matrix decompose ok !" << std::endl;
	}
	return 0;
}

