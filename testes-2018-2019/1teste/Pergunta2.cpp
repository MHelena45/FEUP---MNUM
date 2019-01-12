#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	double a = 1, b = 0.5, c = 0.5;
	return a * pow(x, 7) + b * x - c;
}
int main() {

	 /**************************************/
	 /*          Método da Corda           */
	 /**************************************/
	// metodo mais rapido do que o método da bisseção

	//Intervalo inicial entre 0 e 1
	double xe = 0, xd = 1, xn;

	//Apenas xe vai mudado, obdecendo a formula da recorrência
	//xd mantem-se sempre igual

	cout << fixed << setprecision(6);

	cout << "xe" << setw(10) << "xd" << setw(10) << "xe" << endl;
	
	for (int i = 0; i < 4; i++)
	{
		xn = xd - (f(xd) / (f(xd) - f(xe))*(xd - xe));
		cout << xe << setw(10) << xd << setw(10) << xn  << endl;
		xe = xn;
	}

	return 0;
}