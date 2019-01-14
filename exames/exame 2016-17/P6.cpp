#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//derivada de y
double yl(double x)
{
	double k = 1.5;
	return k * exp(k*x);
}
double f(double x)
{
	return sqrt(1 + pow(yl(x), 2));
}
	/***************************/
	/*    Metodo de Trapezios  */
	/***************************/
double comprimentoT(double h)
{
	//intevalo de integraçao entre a e b,  [0, 2]
	double a = 0, b = 2;

	double x = 0, L;
	L = f(a) + f(b);
	while (x < (b - h))
	{
		x += h;
		L += 2 * f(x);
	}
	L *= (h / 2);
	return L;
}
void Trapezios(double h)
{
	double L1 = comprimentoT(h);
	double L2 = comprimentoT(h / 2);  //diminui-se o passo para metade
	double L3 = comprimentoT(h / 4);  //diminui-se o passo para um quarto

	cout << "O comprimente de L1 e " << L1 << endl;
	cout << "O comprimente de L2 e " << L2 << endl;
	cout << "O comprimente de L3 e " << L3 << endl << endl;

	double Qc = (L2 - L1) / (L3 - L2);
	double erro = (L3 - L2) / 3;

	cout << "O quociente de covergencia no metodo dos trapezios e " << Qc << endl;
	cout << "O erro no metodo dos trapezios e " << erro << endl;
}
	/***********************/
	/*  Metodo de Simpson  */
	/***********************/
double comprimento(double h)
{
	//intevalo de integraçao entre a e b,  [0, 2]
	double a = 0, b = 2;

	double x = 0, L;
	L = f(a) + f(b);
	for (int n = 1; n < (b / h); n++)
	{
		x += h;
		if (n % 2 == 0)
			L += 2 * f(x);
		else
			L += 4 * f(x);
	}
	L *= (h / 3);
	return L;
}
void Simpson(double h)
{
	double L1 = comprimento(h);
	double L2 = comprimento(h / 2);  //diminui-se o passo para metade
	double L3 = comprimento(h / 4);  //diminui-se o passo para um quarto

	cout << "O comprimente de L1 e " << L1 << endl;
	cout << "O comprimente de L2 e " << L2 << endl;
	cout << "O comprimente de L3 e " << L3 << endl << endl;

	double Qc = (L2 - L1) / (L3 - L2);
	double erro = (L3 - L2) / 3;

	cout << "O quociente de covergencia no metodo de Simpson e " << Qc << endl;
	cout << "O erro no metodo de Simpson e " << erro << endl;

}
int main()
{
	/* o numero de intervalos, n = (b-a)/h, tem de ser um numero par !!!!!*/
	//Passo de integração
	double h = 0.5;

	cout << "trapezios " << endl;
	Trapezios(0.5);
	cout << endl << "Simpson " << endl;
	Simpson(0.5);
	system("pause");
	return 0;
}