#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double yl(double z)
{
	return z;
}
double zl(double y, double z)
{
	double A = -6, B = 5;
	return A * z - B * y;
}
int main()
{
	cout << fixed << setprecision(6);
	
	double xn1, xn = 0, h = 0.1;
	double yn1, yn = 2, zn1, zn = 1;
	cout << "xn" << setw(20) << "yn" << setw(20) << "zn" << endl;
	//método de Euler
	for (int i = 0; i < 6; i++)
	{
		cout << xn << setw(20) << yn << setw(20) << zn << endl;
		xn1 = xn + h;
		yn1 = yn + h * yl(zn);
		zn1 = zn + h * zl(yn, zn);
		xn = xn1; yn = yn1; zn = zn1;
	}
	
	system("pause");
	return 0;

}