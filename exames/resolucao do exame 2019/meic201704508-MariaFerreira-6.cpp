#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//p = 8
double f(double x)
{
	return pow(x, 4) + pow(x, 2) - 2 * 8 * x + pow(8, 2);
}
int main()
{
	cout << fixed << setprecision(6);
	//Regra Aurea
	double x1, x2, x3, x4;
	double A, B = (sqrt(5) - 1) / 2;
	A = B * B;
	//Encontrar o minimo no intervalo de -4 a 5
	x1 = 0;
	x2 = 5;
	x3 = A * (x2 - x1) + x1;
	x4 = B * (x2 - x1) + x1;
	while (abs(x1 - x2) > 0.001)
	{
		if (f(x3) < f(x4))
		{
			x2 = x4;
			x4 = x3;
			x3 = A * (x2 - x1) + x1;
		}
		else
		{
			x1 = x3;
			x3 = x4;
			x4 = B * (x2 - x1) + x1;
		}

	}
	cout << "O minimo esta entre :" << endl;
	cout << x3 << " e "<< x4 << endl;
	system("pause");
	return 0;

}