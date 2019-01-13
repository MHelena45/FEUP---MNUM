#include <iostream>
#include <iomanip>
using namespace std;

double f1(double x, double y)
{
	return x * x - y - 1.2;
}

double f2(double x, double y)
{
	return -x + y * y - 1;
}
//derivada parcial de f1 em ordem a x
double f1x(double x, double y)
{
	return 2 * x;
}
//derivada parcial de f1 em ordem a x
double f1y(double x, double y)
{
	return -1;
}
//derivada parcial de f2 em ordem a x
double f2x(double x, double y)
{
	return -1;
}
//derivada parcial de f2 em ordem a x
double f2y(double x, double y)
{
	return 2 * y;
}
int main()
{
	double xn1, xn = 1;
	double yn1, yn = 1;
	cout << "xn" << setw(10) << "yn" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << xn << setw(10) << yn << endl;
		xn1 = xn - ((f1(xn, yn)*f2y(xn, yn) - f2(xn, yn) * f1y(xn, yn)) /
			(f1x(xn, yn) * f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn)));
		yn1 = yn - ((f2(xn, yn)*f1x(xn, yn) - f1(xn, yn) * f2x(xn, yn)) /
			(f1x(xn, yn) * f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn)));
		xn = xn1;
		yn = yn1;
	}
	system("pause");
	return 0;
}