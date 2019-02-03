#include <iostream>
#include <iomanip>
using namespace std;
//double utiliza 14 casas decimais
double C(double T, double C)
{
	double b = 0.5;
	return -exp(-b / (T + 273))*C;
}

double T(double T, double C)
{
	double a=30, b = 0.5;
	return a*exp(-b / (T + 273))*C-b*(T-20);
}

double euler(double t0, double tF, double h, bool output)
{
	double t, Cn = 2.5, Tn = 25;
	double Tn1, Cn1;
	double n = (tF - t0)/ h;
	t = t0;
	if (output)
	{
		cout << "iter" << setw(12) << "t" << setw(19) << "Cn" << setw(19) << "Tn" << endl;
		cout << "0" << setw(15)<< t0 << setw(19) << Cn << setw(19)<< Tn << endl;
	}
	
	for (int i = 1; i < (n+1); i++)
	{	
		Tn1 = Tn + h * T(Tn, Cn);
		Cn1 = Cn + h * C(Tn, Cn);
		t = t + h;		
		Cn = Cn1;
		Tn = Tn1;
		if (output) {
			cout << i << setw(15) << t << setw(19) << Cn << setw(19) << Tn << endl;
		}
		
	}	
	return Cn;
}
void RK4(double h)
{
	double t = 0, Cn = 2.5, Tn = 25;
	double d1C, d2C, d3C, d4C;
	double d1T, d2T, d3T, d4T;
	cout << "iter" << setw(12) << "t" << setw(19) << "Cn" << setw(19) << "Tn" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << setw(15) << t << setw(19) << Cn << setw(19) << Tn << endl;

		d1T = h * T(Tn, Cn);
		d1C = h * C(Tn, Cn);

		d2T = h * T(Tn + d1T/2, Cn + d1C/2);
		d2C = h * C(Tn + d1T/2, Cn + d1C / 2);

		d3T = h * T(Tn + d2T / 2, Cn + d2C / 2);
		d3C = h * C(Tn + d2T / 2, Cn + d2C / 2);

		d4T = h * T(Tn + d3T, Cn + d3C);
		d4C = h * C(Tn + d3T, Cn + d3C);

		Cn += d1C / 6 + d2C / 3 + d3C / 3 + d4C / 6;
		Tn += d1T / 6 + d2T / 3 + d3T / 3 + d4T / 6;
		t += h;

	}
}
int main()
{
	cout << fixed << setprecision(8); //precisao do resultado mostrado

	double h= 0.1; //passo de integração
	double t0 = 0, tF = 0.2;  //t inicial e final
	double S, Sl, Sll;   //resultados consonte o passo

	cout << "´Metodo de Euler" << endl;
	S = euler(t0, tF, h, true);

	cout << endl << "Metodo de RK4" << endl;
	RK4(h);

	Sl = euler(t0, tF, h / 2, false);
	cout << endl << "hl = " << h / 2 << setw(10);
	cout << "  Chl:  "<< Sl << endl;

	Sll = euler(t0, tF, h / 4, false);
	cout << "hll = " << h / 4 << setw(10);
	cout  << "  Chll:  "<< Sll << endl;

	cout  << endl<< "Qc =  " << (Sl - S) / (Sll - Sl) << endl;
	cout << "erro = " << (Sll - Sl) << endl;

	system("pause");
	return 0;
}