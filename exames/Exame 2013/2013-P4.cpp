#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x)
{
	double c = 1.5;
	return exp(c*x);
}
double Simpson(double a, double b, double h)
{
	double S = f(a) + f(b);
	double n = (b - a) / h;
	for (int i = 1; i < n; i++)
	{
		if (i % 2)
		{
			S += 4 * f(a + h * i);
		}
		else {
			S += 2 * f(a + h * i);
		}
	}
	return (h/3)*S;
}
int main()
{
	cout << fixed << setprecision(7);
	cout << endl;
	cout << setw(5) << " h" << setw(40) << "valor do integral" << endl;
	double h = 0.125, a = 1, b = 1.5;
	double S = Simpson(a, b, h);
	cout << "h:   " << h << setw(20) << "S:    " << S << endl;

	double Sl = Simpson(a, b, h/2);
	cout << "hl:  " << h/2 << setw(19) << "Sl:  " << Sl << endl;

	double Sll = Simpson(a, b, h/4);
	cout << "hll: " << h/4 << setw(20) << "Sll:  "<< Sll << endl;

	double Qc = (Sl - S) / (Sll - Sl);
	cout << endl << "Qc: " << Qc << endl;

	double erro = (Sll - Sl) / (pow(4, 2) - 1);
	cout << "erro: " << abs(erro)/Sll << endl;

	cout << S << endl;
	cout << "erro absoluto: " << erro << endl;
	system("pause");
	return 0;

}
