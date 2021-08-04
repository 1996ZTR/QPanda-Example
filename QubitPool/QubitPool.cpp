#include "QPanda.h"
USING_QPANDA
using namespace std;
int main()
{
	// 量子比特可以和虚拟机 脱离关系，获取对应池的单例
	auto qpool = OriginQubitPool::get_instance();
	auto cmem = OriginCMem::get_instance();

	//获取容器大小
	cout << "set qubit pool capacity  before: " << qpool->get_capacity() << endl;
	// 设置最大容器
	qpool->set_capacity(20);
	cout << "set qubit pool capacity  after: " << qpool->get_capacity() << endl;

	// 通过比特池申请比特，由于是单例模式，要保证申请的比特数量不超过最大容量
	auto qv = qpool->qAllocMany(6);
	auto cv = cmem->cAllocMany(6);

	// 获取被申请的量子比特
	QVec used_qv;
	auto used_qv_size = qpool->get_allocate_qubits(used_qv);
	cout << "allocate qubits number: " << used_qv_size << endl;

	// 构建虚拟机
	auto qvm = new CPUQVM();
	qvm->init();
	auto prog = QProg();
	// 直接使用物理地址作为量子比特信息入参
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

	// 测量方法也可以使用比特物理地址 
	auto res_0 = qvm->probRunDict(prog, { 0,1,2,3,4,5 });
	// auto res_1 = qvm->probRunDict(prog, qv);  //同等上述方法


	// 同样经典比特地址也可以作为经典比特信息入参
	prog << Measure(0, 0)
		<< Measure(1, 1)
		<< Measure(2, 2)
		<< Measure(3, 3)
		<< Measure(4, 4)
		<< Measure(5, 5)
		;

	// 使用经典比特地址入参 
	vector<int> cbit_addrs = { 0,1,2,3,4,5 };
	auto res_2 = qvm->runWithConfiguration(prog, cbit_addrs, 5000);
	// auto res_3 = qvm->runWithConfiguration(prog, cv, 5000); //同等上述方法
	qvm->finalize();
	delete(qvm);


	// 同时我们还可以再次利用这里申请的qv，避免多次使用虚拟机多次申请比特的问题发生
	auto qvm_noise = new NoiseQVM();
	qvm_noise->init();
	auto res_4 = qvm_noise->runWithConfiguration(prog, cbit_addrs, 5000);
	qvm_noise->finalize();
	delete(qvm_noise);

	return 0;
}

