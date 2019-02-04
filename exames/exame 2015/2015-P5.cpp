#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double yl(double x)
{
	return 2.5 *exp(2.5 * x);
}
double L(double x)
{
	return pow(1+ pow(yl(x), 2), 0.5);
}

double MTrapezios(double a, double b, double h)
{
	double s = L(a) + L(b);
	a += h;
	for(int i = a; a < b;a += h )
	{	
		s += 2 * L(a);	
	}
	s*= (h / 2);
	return s;
}
double MSimpson(double a, double b, double h)
{
	double s = L(a) + L(b);
	double n = (b - a) / h;
	for (int i = 1; i < n; i++)
	{		
		if (i % 2)
		{
			s += 4 * L(a + i *h);
		}
		else {
			s += 2 * L(a + i * h);
		}
		
	}
	s *= (h / 3);
	return s;
}
int main()
{
	cout << fixed << setprecision(6);

	double a = 0, b =1, h = 0.125;
	double T, Tl, Tll;
	double S, Sl, Sll;

	cout << "h " << setw(20) << h << setw(20) << h << endl;
	cout << "hl " << setw(19) << h/2 << setw(20) << h/2 << endl;
	cout << "hll " << setw(18) << h/4 << setw(20) << h/4 << endl;

	cout << endl << "Metodo dos Trapezios " << setw(20) << "Metodo de Simpson " << endl;
	T = MTrapezios(a, b, h);
	S = MSimpson(a, b, h);
	cout << T << setw(25) << S << endl;

	Tl = MTrapezios(a, b, h/2);
	Sl = MSimpson(a, b, h/2);
	cout << Tl << setw(25) << Sl << endl;

	Tll = MTrapezios(a, b, h /4);
	Sll = MSimpson(a, b, h/4);
	cout << Tll << setw(25)<< Sll << endl;

	double TQc = (Tl - T) / (Tll - Tl);
	double SQc = (Sl - S) / (Sll - Sl);
	cout << TQc << setw(26) << SQc << endl;

	double erroS = (Sll - Sl) / 3;
	double erroT = (Sll - Sl) /( pow(4,2)-1);
	cout << abs(erroS) << setw(25) << abs(erroT) << endl;

	system("pause");
	return 0;

}