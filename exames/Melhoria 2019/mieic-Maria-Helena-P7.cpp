#include <iomanip>
#include <iostream>
using namespace std;
double rcub(double x)
{
	return pow(x, (1/3));
}
double derivada(double x)
{
	return 1 / (3 * pow(x, (2 / 3)));
}
int main()
{
	double precisao, xn, xn1;
	int Niter = 0;
	cout << "Qual o valor de x? " << endl;
	cin >> xn1;
	cout << endl << "Qual o valor da precisao pretendida ? " << endl;
	cin >> precisao ;

	do
	{
		xn = xn1;
		xn1 = xn - (rcub(xn) / derivada(xn));	
		Niter++;
	} while (rcub(xn1)> precisao);

	cout << endl << "O valor do zero e " << xn1 << endl;
	cout << "Foram necessárias " << Niter << " iteracoes " << endl;
	system("pause");
	return 0;
}