#include "QPanda.h"
USING_QPANDA

int main()
{
	using namespace QPanda::Variational;

	MatrixXd train_x(17, 1);
	MatrixXd train_y(17, 1);

	train_x(0, 0) = 3.3;
	train_x(1, 0) = 4.4;
	train_x(2, 0) = 5.5;
	train_x(3, 0) = 6.71;
	train_x(4, 0) = 6.93;
	train_x(5, 0) = 4.168;
	train_x(6, 0) = 9.779;
	train_x(7, 0) = 6.182;
	train_x(8, 0) = 7.59;
	train_x(9, 0) = 2.167;
	train_x(10, 0) = 7.042;
	train_x(11, 0) = 10.791;
	train_x(12, 0) = 5.313;
	train_x(13, 0) = 7.997;
	train_x(14, 0) = 5.654;
	train_x(15, 0) = 9.27;
	train_x(16, 0) = 3.1;
	train_y(0, 0) = 1.7;
	train_y(1, 0) = 2.76;
	train_y(2, 0) = 2.09;
	train_y(3, 0) = 3.19;
	train_y(4, 0) = 1.694;
	train_y(5, 0) = 1.573;
	train_y(6, 0) = 3.366;
	train_y(7, 0) = 2.596;
	train_y(8, 0) = 2.53;
	train_y(9, 0) = 1.221;
	train_y(10, 0) = 2.827;
	train_y(11, 0) = 3.465;
	train_y(12, 0) = 1.65;
	train_y(13, 0) = 2.904;
	train_y(14, 0) = 2.42;
	train_y(15, 0) = 2.94;
	train_y(16, 0) = 1.3;

	var X(train_x);
	var Y(train_y);

	var W(1.0, true);
	var b(1.0, true);

	var Y_ = W * X + b;
	auto loss = sum(poly(Y - Y_, 2) / train_x.rows());
	auto optimizer = VanillaGradientDescentOptimizer::minimize(loss, 0.01, 1.e-6);

	auto leaves = optimizer->get_variables();
	for (size_t i = 0u; i < 1000; i++)
	{
		optimizer->run(leaves);
		std::cout << "i: " << i << "\t" << optimizer->get_loss()
			<< "\t W:" << QPanda::Variational::eval(W, true)
			<< "\t b:" << QPanda::Variational::eval(b, true)
			<< std::endl;
	}

	return 0;
}

