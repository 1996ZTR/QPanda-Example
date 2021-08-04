#include "QPanda.h"
USING_QPANDA
using namespace std;
int main()
{
	// ���ӱ��ؿ��Ժ������ �����ϵ����ȡ��Ӧ�صĵ���
	auto qpool = OriginQubitPool::get_instance();
	auto cmem = OriginCMem::get_instance();

	//��ȡ������С
	cout << "set qubit pool capacity  before: " << qpool->get_capacity() << endl;
	// �����������
	qpool->set_capacity(20);
	cout << "set qubit pool capacity  after: " << qpool->get_capacity() << endl;

	// ͨ�����س�������أ������ǵ���ģʽ��Ҫ��֤����ı��������������������
	auto qv = qpool->qAllocMany(6);
	auto cv = cmem->cAllocMany(6);

	// ��ȡ����������ӱ���
	QVec used_qv;
	auto used_qv_size = qpool->get_allocate_qubits(used_qv);
	cout << "allocate qubits number: " << used_qv_size << endl;

	// ���������
	auto qvm = new CPUQVM();
	qvm->init();
	auto prog = QProg();
	// ֱ��ʹ�������ַ��Ϊ���ӱ�����Ϣ���
	prog << H(0) << H(1)
		<< H(2)
		<< H(4)
		<< X(5)
		<< X1(2)
		<< CZ(2, 3)
		<< RX(3, PI / 4)
		<< CR(4, 5, PI / 2)
		<< SWAP(3, 5)
		<< CU(1, 3, PI / 2, PI / 3, PI / 4, PI / 5)
		<< U4(4, 2.1, 2.2, 2.3, 2.4)
		<< BARRIER({ 0, 1,2,3,4,5 })
		;

	// ��������Ҳ����ʹ�ñ��������ַ 
	auto res_0 = qvm->probRunDict(prog, { 0,1,2,3,4,5 });
	// auto res_1 = qvm->probRunDict(prog, qv);  //ͬ����������


	// ͬ��������ص�ַҲ������Ϊ���������Ϣ���
	prog << Measure(0, 0)
		<< Measure(1, 1)
		<< Measure(2, 2)
		<< Measure(3, 3)
		<< Measure(4, 4)
		<< Measure(5, 5)
		;

	// ʹ�þ�����ص�ַ��� 
	vector<int> cbit_addrs = { 0,1,2,3,4,5 };
	auto res_2 = qvm->runWithConfiguration(prog, cbit_addrs, 5000);
	// auto res_3 = qvm->runWithConfiguration(prog, cv, 5000); //ͬ����������
	qvm->finalize();
	delete(qvm);


	// ͬʱ���ǻ������ٴ��������������qv��������ʹ����������������ص����ⷢ��
	auto qvm_noise = new NoiseQVM();
	qvm_noise->init();
	auto res_4 = qvm_noise->runWithConfiguration(prog, cbit_addrs, 5000);
	qvm_noise->finalize();
	delete(qvm_noise);

	return 0;
}

