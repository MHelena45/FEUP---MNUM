#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/***********************/
/*     Pergunta 4     */
/***********************/

double fC(double t, double C, double T)
{
	float b = 0.5;
	return (-exp(-b / (T + 273)) * C);
}

double fT(double t, double C, double T) { 
	float a = 20, b = 0.5;
	return (a*exp(-b / (T + 273))*C - b * (T - 20)); 
}

double mEuler(double h, bool output, int iteracoes)
{
	double t = 0, Cn = 2, Tn = 20;
	double Cn1, Tn1;
	if (output) {
		cout << "t" << setw(20) << "C" << setw(20) << "T" << endl;
		cout << t << setw(20) << Cn << setw(20) << Tn << endl;
	}
	
	for (int i = 0; i < iteracoes; i++)
	{
		t += h;
		Cn1 = Cn + h * fC(t, Cn, Tn);
		Tn1 = Tn + h * fT(t, Cn, Tn);
		Cn = Cn1;
		Tn = Tn1;
		if (output) {
			cout << t << setw(20) << Cn << setw(20) << Tn << endl;
		}
		
	}
	return Cn;
}

void mRK4() 
{
	double tn = 0, Cn = 2, Tn = 20;
	double h = 0.2, Cn1, Tn1, tn1;
	double dC1, dC2, dC3, dC4;
	double dT1, dT2, dT3, dT4;

	cout << "t" << setw(20) << "C" << setw(20) << "T" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << tn << setw(20) << Cn << setw(20) << Tn << endl;
		tn1 = tn + h;

		dC1 = h * fC(tn, Cn, Tn);
		dT1 = h * fT(tn, Cn, Tn);

		dC2 = h * fC(tn + h / 2, Cn + dC1/2, Tn + dT1/2);
		dT2 = h * fT(tn + h / 2, Cn + dC1/2, Tn + dT1/2);

		dC3 = h * fC(tn + h / 2, Cn + dC2 / 2, Tn + dT2 / 2);
		dT3 = h * fT(tn + h / 2, Cn + dC2 / 2, Tn + dT2 / 2);

		dC4 = h * fC(tn1, Cn + dC3, Tn + dT3);
		dT4 = h * fT(tn1, Cn + dC3, Tn + dT3);

		Cn += dC1 / 6 + dC2 / 3 + dC3 / 3 + dC4 / 6;
		Tn += dT1 / 6 + dT2 / 3 + dT3 / 3 + dT4 / 6;

		tn = tn1;
	}

}
void Qc(double hInicial)
{
	double C = mEuler(hInicial,0, 2);
	double Cl = mEuler(hInicial/2 , 0, 4);
	cout << "C hl = " << Cl << endl;
	double Cll = mEuler(hInicial /4, 0, 8);
	cout << "C hll = " << Cll << endl;

	double Qc = (Cl - C) / (Cll - Cl);
	cout << "Qc = " << Qc << endl;

	double erro = (Cll - Cl);
	cout << "erro = " << erro << endl;
}
int main()
{
	cout << fixed << setprecision(7);
	double h = 0.2;

	/*  Alinea A  */

	cout << "Metodo de Euler " << endl << endl;
	mEuler(h, 1, 2);

	/*  Alinea B  */

	cout << endl << "Metodo de Runge-Kutta 4 " << endl << endl;
	mRK4();

	/*  Alinea C  */
	//hl = h/2 = 0.01
	//hll = h/4 = 0.005
	Qc(h);

	system("pause");
	return 0;
}