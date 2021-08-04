#include "QPanda.h"
USING_QPANDA

int main()
{
	using namespace QPanda::Variational;

	var const_var(1);

	MatrixXd m1(2, 2);
	m1 << 1, 2, 3, 4;

	MatrixXd m2(2, 2);
	m2 << 5, 6, 7, 8;

	var var1(m1);
	var var2(m2);

	var sum = var1 + var2;
	var minus(op_type::minus, { var2, var1 });
	var multiply = var1 * var2;

	MatrixXd dx = MatrixXd::Ones(2, 2);

	std::cout << "const_var: " << std::endl << const_var.getValue() << std::endl;
	std::cout << "var1: " << std::endl << var1.getValue() << std::endl;
	std::cout << "var2: " << std::endl << var2.getValue() << std::endl;
	std::cout << "sum: " << std::endl << sum._eval() << std::endl;
	std::cout << "    op_type: " << int(sum.getOp()) << std::endl;
	std::cout << "    NumOpArgs: " << int(sum.getNumOpArgs()) << std::endl;
	std::cout << "minus: " << std::endl << minus._eval() << std::endl;
	std::cout << "    op_type: " << int(minus.getOp()) << std::endl;
	std::cout << "    NumOpArgs: " << int(minus.getNumOpArgs()) << std::endl;
	std::cout << "multiply: " << std::endl << multiply._eval() << std::endl;
	std::cout << "    op_type: " << int(multiply.getOp()) << std::endl;
	std::cout << "    NumOpArgs: " << int(multiply.getNumOpArgs()) << std::endl;
	std::cout << "Derivative multipy to var1:" << std::endl << multiply._back_single(dx, 0) << std::endl;
	std::cout << "Derivative multipy to var2:" << std::endl << multiply._back_single(dx, 1) << std::endl;


	MatrixXd m3(2, 2);
	m3 << 4, 3, 2, 1;
	var1.setValue(m3);

	std::cout << "sum: " << std::endl << sum._eval() << std::endl;
	std::cout << "minus: " << std::endl << minus._eval() << std::endl;
	std::cout << "multiply: " << std::endl << multiply._eval() << std::endl;
	std::cout << "matrix_var1 UseCount: " << var1.getUseCount() << std::endl;

	return 0;
}

