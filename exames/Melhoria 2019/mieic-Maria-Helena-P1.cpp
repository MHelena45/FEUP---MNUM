#include <iomanip>
#include <iostream>
using namespace std;
double f(double x)
{
	return log(4 + x);
}
int main()
{
	//intervalo de 1.5 a 2
	double precisao = 0.000001, xn1= 1.5, xn;
	int Niter = 0;
	do
	{
		xn = xn1;
		xn1 = f(xn);
		Niter++;
	} while (f(xn1) > precisao);

	cout << endl << "O valor do zero e " << xn1 << endl;
	cout << "Foram necessarias " << Niter << " iteracoes " << endl;
	system("pause");
	return 0;
}