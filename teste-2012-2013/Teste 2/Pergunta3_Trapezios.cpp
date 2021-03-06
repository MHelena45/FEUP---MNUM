#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//derivada de y
double yl(double x)
{
	double k = 1.5;
	return k*exp(k*x);
}
double f(double x)
{
	return sqrt(1 + pow(yl(x), 2));
}
double comprimento(double h)
{
	//intevalo de integraçao entre a e b,  [0, 1]
	double a = 0, b = 1;

	double x = 0, L;
	L = f(a) + f(b);
	while (x < (b-h))
	{ 		
		x += h;
		L += 2 * f(x);
	}
	L *= (h / 2);
	return L;
}
int main()
{
	//Passo de integração
	double h = 0.25;
	double L1 = comprimento(h);
	double L2 = comprimento(h / 2);  //diminui-se o passo para metade
	double L3 = comprimento(h / 4);  //diminui-se o passo para um quarto

	cout << "O comprimente de L1 e " << L1 << endl;
	cout << "O comprimente de L2 e " << L2 << endl;
	cout << "O comprimente de L3 e " << L3 << endl << endl;

	double Qc = (L2 - L1) / (L3 - L2);
	double erro = (L3 - L2) /3;

	cout << "O quociente de covergencia no metodo dos trapezios e " << Qc << endl;
	cout << "O erro no metodo dos trapezios e " << erro << endl;
	system("pause");
	return 0;
}