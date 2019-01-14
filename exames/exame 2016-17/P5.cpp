#include <iostream>
#include <iomanip>
using namespace std;
/*
dado que e uma equação diferencia de 2ª ordem
	(dy/dt) = z;
	(dz/dt) = A + pow(t,2) + t * z;
*/
double yl(double z)
{
	return z;
}
double zl(double t, double z)
{
	double A = 0.5;
	return A + pow(t, 2) + t * z;
}
void euler(double h)
{
	cout << "tn" << setw(10) << "yn" << setw(10) << "zn" << endl;
	double tn1, tn = 0, yn1, yn = 0, zn1, zn = 1;
	for (int i = 0; i < 3; i++)
	{
		cout << tn << setw(10) << yn << setw(10) << zn << endl;
		tn1 = tn + h;
		yn1 = yn + h * yl(zn);
		zn1 = zn + h * zl(tn, zn);
		zn = zn1; yn = yn1; tn = tn1;	
	}
}
void RK4(double h)
{
	double dy1, dy2, dy3, dy4;
	double dz1, dz2, dz3, dz4;
	double tn = 0, yn = 0, zn = 1;
	cout << "n" << setw(10) << "tn" << setw(20) << "yn" << endl;
	cout << "0" << setw(10) << tn << setw(20) << yn << endl;
	for (unsigned int i = 1; i <= 3; i++)
	{
		dy1 = h * yl(zn);
		dz1 = h * zl(tn, zn);

		dy2 = h * yl(zn + (dz1 / 2));
		dz2 = h * zl(tn + h / 2, zn + (dz1 / 2));

		dy3 = h * yl(zn + (dz2 / 2));
		dz3 = h * zl(tn + h / 2, zn + dz2 / 2);

		dy4 = h * yl(zn + dz3);
		dz4 = h * zl(tn + h, zn + dz3);

		yn += (dy1 / 6) + (dy2 / 3) + (dy3 / 3) + (dy4 / 6);
		zn += (dz1 / 6) + (dz2 / 3) + (dz3 / 3) + (dz4 / 6);
		tn += h;

		cout << i << setw(10) << tn << setw(20) << yn << endl;
	}
	
}

int main()
{
	cout << fixed << setprecision(7);
	cout << "Metodo de euler " << endl << endl;
	euler(0.25); //parametro que define o passo de integração
	
	cout << endl << "RK4 " << endl << endl;
	RK4(0.25);
	system("pause");
	return 0;
}