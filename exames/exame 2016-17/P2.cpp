#include <iostream>
#include <iomanip>
using namespace std;
double f1(double x, double y)
{
	return x * x - y - 1.2;
}
double fl1x(double x, double y)
{
	return 2 * x;
}
double fl1y(double x, double y)
{
	return -1;
}
double f2(double x, double y)
{
	return -x + y * y - 1;
}
double fl2x(double x, double y)
{
	return -1;
}
double fl2y(double x, double y)
{
	return 2*y;
}
int main()
{
	double xn1, xn = 1, yn1, yn = 1;
	double h;
	cout << "xn1 " << setw(15) << "yn1" << endl;
	for (int i = 0; i < 3; i++)
	{
		xn1 = xn - (f1(xn,yn)*fl2y(xn,yn) - f2(xn,yn)*fl1y(xn,yn))
			/(fl1x(xn,yn)*fl2y(xn, yn) - fl2x(xn,yn)*fl1y(xn,yn));
		yn1 = yn - (f2(xn, yn)*fl1x(xn, yn) - f1(xn, yn)*fl2x(xn, yn))
			/ (fl1x(xn, yn)*fl2y(xn, yn) - fl2x(xn, yn)*fl1y(xn, yn));
		cout << xn1 << setw(15) << yn1 << endl;
		xn = xn1; yn = yn1;
	}
	
	system("pause");
	return 0;
}