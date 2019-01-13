#include <iostream>
#include <iomanip>
using namespace std;
double f(double t ,double y)
{
	double a = 1;
	return y / (t - a);
}
void RK4(double h, double t, double y)
{
	double d1, d2, d3, d4;
	cout << fixed << setprecision(6);
	cout << "t" << setw(15) << "y" << setw(15) << "d1" << setw(15) << "d2" << setw(15) << "d3" << setw(15) << "d4" << endl;
	for(int i= 0; i < 3; i++)
	{
		d1 = h * f(t, y);
		d2 = h * f(t + (h / 2), y + (d1 / 2));
		d3 = h * f(t + (h / 2), y + (d2 / 2));
		d4 = h * f(t + h, y + d3);
		cout << t << setw(15) << y << setw(15) << d1 << setw(15) << d2 << setw(15) << d3 << setw(15) << d4 << endl;
		y += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
		t += h;
	}
}
void Euler(double h, double t, double y)
{
	for (int i = 0; i < 3; i++)
	{
		cout << t << setw(10) << y << endl;
		y += h * f(t, y);
		t += h;	
	}
}
int main()
{	
	double h = 0.25;

	cout << "Metodo de Euler \n";
	Euler(h, 2, 2);

	cout << "RK4" << endl << endl;
	RK4(h, 2, 3);
	system("pause"); 
	return 0;
}