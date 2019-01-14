#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	return pow(x,7) + 0.5 * x - 0.5;
}

int main()
{
	//xd mantem-se constante
	double xe=0, xn, xd = 0.8;
	cout << fixed << setprecision(6);
	for (int i = 0; i < 4; i++)
	{
		xn = xe - (f(xe) / (f(xe) - f(xd)))*(xe - xd);
		cout << xe << setw(10) << xd << setw(10) << xn << setw(10) << f(xe) << setw(10) << f(xd) << setw(10) << f(xn) << endl;
		xe = xn;
	}
	system("pause");
	return 0;
}