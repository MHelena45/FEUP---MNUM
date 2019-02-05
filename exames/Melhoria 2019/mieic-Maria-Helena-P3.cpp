#include <iomanip>
#include <iostream>
using namespace std;
//V(1) - V(2.5) = integrate(Dv/du,du,1,2.5)
double dv(double u, double v)
{
	return u * ((u / 2 + 1)*pow(v, 3) + (u + (5 / 2))*pow(v, 2));
}
double RK4(double u, double b, double v , double h)
{
	double d1, d2, d3, d4;
	while(u < b) {
		d1 = h * dv(u, v);
		d2 = h * dv(u + h/2, v + d1/2);
		d3 = h * dv(u + h/2, v + d2/2);
		d4 = h * dv(u + h, v + d3);
		v += (d1 / 6) + (d2 / 3) + (d3 / 3) + (d4 / 6);
		u += h;
	}
	return v;
}
int main()
{
	double a = 1, b = 2.5, v = 0.1;
	double h = 0.15;
	double vh, vhl, vhll;

	vh = RK4(a, b,v, h);
	cout << h << setw(20) << vh << endl;

	vhl = RK4(a, b, v, h/2);
	cout << h/2 << setw(20) <<  vhl << endl;

	vhll = RK4(a, b,v,  h/4);
	cout << h/4 << setw(20) << vhll << endl;

	double Qc = (vhl - vh) / (vhll - vhl);
	double erro = (vhll - vhl) / 15;
	cout << "Qc: " << Qc << endl;
	cout << "Erro: " << erro << endl;
	system("pause");
	return 0;
}