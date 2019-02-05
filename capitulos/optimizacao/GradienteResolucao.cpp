#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Z(double x, double y)
{
	return 6 * pow(x, 2) -x *y + 12 * y + y * y - 8 * x;
}

//No maxima
//eq1: 3*x^2-x*y+11*y+y^2-8*x;
//diff(eq1,x);
double Zx(double x, double y)
{
	return -y + 12 * x - 8;
}

//diff(eq1,y);
double Zy(double x, double y)
{
	return 2 * y - x + 12;
}

int gradiente(double x,double y, double lambda, double precisao) {
	int iteracoes = 0;
	double xn1, yn1;
	bool final = false;
	double Gx = Zx(x, y), Gy = Zy(x,y);

	xn1 = x - lambda * Gx;
	yn1 = y - lambda * Gy;
	while (abs(xn1 - x) > precisao || abs(yn1 - y) > precisao)
	{
		iteracoes++;
		if (final) {
			x = xn1;
			y = yn1;
		}
		xn1 = x - lambda * Gx;
		yn1 = y - lambda * Gy;
		if (Z(xn1, yn1) < Z(x, y))
		{
			final = true;
			lambda *= 2;
		}
		else
		{
			final = false;
			lambda /= 2;
		}		
	}

	cout << setw(5) << "Xn" << setw(20) << "Z(Xn)" << setw(25) << "Gradient" << endl;
	cout << xn1 << setw(20) << Z(xn1, yn1) << setw(20) << Zx(xn1, yn1) << endl;
	cout << yn1 << setw(40) << Zy(xn1, yn1) << endl;
	return iteracoes;
}

int main()
{
	cout << fixed << setprecision(7);

	double x = 0, y = 0, lambda = 2, precisao = 0.001;
	int G2, G1, G05, G025;

	cout << setw(5) << "Xn" << setw(20) << "Z(Xn)" << setw(25) << "Gradient" << endl;
	cout << x << setw(20) << Z(x,y) << setw(20) << Zx(x, y) << endl;
	cout << y << setw(40)  << Zy(x, y) << endl << endl;

	cout << "lambda = " << lambda << endl;
	G2 = gradiente(x, y, lambda, precisao);	
	cout << "N de iteracoes: "<< G2 << endl << endl; 
	
	cout << "lambda = " << lambda/2 << endl;
	G1 = gradiente(x, y, lambda/2, precisao);	
	cout << "N de iteracoes: " << G1 << endl << endl;

	cout << "lambda = " << lambda/4 << endl;
	G05 = gradiente(x,y, lambda/4, precisao);
	cout << "N de iteracoes: " << G05 << endl << endl;

	cout << "lambda = " << lambda/8 << endl;
	G025 = gradiente(x, y, lambda/8, precisao);
	cout << "N de iteracoes: " << G025 << endl << endl;
	
	system("pause");
	return 0;

}
