#include "QPanda.h"
USING_QPANDA

int main()
{
	auto qvm = initQuantumMachine();
	auto q = qvm->qAllocMany(5);
	auto c = qvm->cAllocMany(5);

	QProg prog;
	QCircuit replace_cir, query_cir;

	// �������ӳ���
	prog << H(q[0])
		<< H(q[2])
		<< H(q[3])
		<< CNOT(q[1], q[0])
		<< H(q[0])
		<< CNOT(q[1], q[2])
		<< H(q[2])
		<< CNOT(q[2], q[3])
		<< H(q[3]);

	std::cout << "��ѯ�滻ǰ��" << std::endl;
	std::cout << convert_qprog_to_originir(prog, qvm) << std::endl;

	// ������ѯ��·�� �����滻��·
	query_cir << H(q[0]) << CNOT(q[1], q[0]) << H(q[0]);
	replace_cir << CZ(q[0], q[1]);
	const std::vector<std::pair<QCircuit, QCircuit>>  replace_cir_vec = { {query_cir, replace_cir} };

	// �������ӳ����еĲ�ѯ��·�������滻��·���,����ı�ԭ��prog�Ľṹ
	sub_cir_replace(prog, replace_cir_vec);

	std::cout << std::endl;
	std::cout << "��ѯ�滻��" << std::endl;
	std::cout << convert_qprog_to_originir(prog, qvm) << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}
