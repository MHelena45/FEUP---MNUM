#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//começamos por igualar a 0
double f1(double x, double y)
{
	return exp(x - y) - sin(x + y);
}
//No maxima diff(%e^(x-y)-sin(x+y),x);
double fl1x(double x, double y)
{
	return exp(x - y) - cos(x + y);
}
//No maxima diff(%e^(x-y)-sin(x+y),y);
double fl1y(double x, double y)
{
	return -exp(x - y) - cos(x + y);
}

double f2(double x, double y)
{
	return pow(x,2)*pow(y,2)- cos(x + y);
}
//No maxima diff(cos(x+y)-x^2*y^2,x);
double fl2x(double x, double y)
{
	return -sin(x + y) - 2 * x*pow(y, 2);
}
//No maxima diff(cos(x+y)-x^2*y^2,y);
double fl2y(double x, double y)
{
	return -sin(x + y) - 2 * y*pow(x, 2);
}
int main()
{
	double xn1, yn1, xn, yn;
	xn = -0.5, yn = 1;
	cout << fixed << setprecision(8);
	cout << "xn" << setw(20) << "yn" << endl;
	for (int i = 0; i < 3; i++)
	{
		xn1 = xn - ((f1(xn, yn)*fl2y(xn, yn) - f2(xn, yn)*fl1y(xn, yn)) /
			(fl1x(xn, yn)*fl2y(xn, yn) - fl2x(xn, yn)*fl1y(xn, yn)));
		yn1 = yn - ((f2(xn, yn)*fl1x(xn, yn) - f1(xn, yn)*fl2x(xn, yn)) /
			(fl1x(xn, yn)*fl2y(xn, yn) - fl2x(xn, yn)*fl1y(xn, yn)));
		cout << xn << setw(20) << yn << endl;
		xn = xn1; yn = yn1;
		
	}
	
	system("pause");
	return 0;

}