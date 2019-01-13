#include <iostream>
#include <iomanip>
using namespace std;
double f(double t ,double x)
{
	double a = 1, b = 2;
	return sin(a*x) + sin(b * t);
}
int main()
{
	double h = 0.125;
	double d1, d2, d3, d4,t= 1, x=1;
	cout << fixed << setprecision(6);

	while (t < 1.5) {
		d1 = h * f(t, x);
		d2 = h * f(t + h / 2, x + (d1 / 2));
		d3 = h * f(t + (h / 2), x + (d2 / 2));
		d4 = h * f(t + h, x + d3);
		x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
		cout << t << setw(15) << x << endl;
	}
	
	/* Como podemos ver pela a imagem */
	double I = 1.767816, Il = 1.768150;
	double Qc = (Il - I) / (x - Il);
	cout << "Qc = " << Qc  << endl;
	system("pause"); 
	return 0;
}