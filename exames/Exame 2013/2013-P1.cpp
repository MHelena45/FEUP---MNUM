#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double yl(double z)
{
	return z;
}
double yll(double t, double z)
{
	double A = 0.5;
	return A + pow(t, 2) + t * z;
}
void euler(double h, double t, double y, double z)
{
	cout << "i" << setw(20) << "t" << setw(20) << "y" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << setw(20) << t << setw(20) << y << endl;
		y += h * yl(z);
		z += h * yll(t, z);
		t += h;
	}
	
}
void RK4(double h, double t, double y, double z)
{
	cout << "i" << setw(20) << "t" << setw(20) << "y" << endl;
	double d1y, d2y, d3y, d4y;
	double d1z, d2z, d3z, d4z;
	for (int i = 0; i < 3; i++)
	{
		cout << i << setw(20) << t << setw(20) << y << endl;
		d1y = h * yl(z);
		d1z = h * yll(t + h / 2, z);

		d2z = h * yll(t + h / 2, z + d1z / 2);
		d2y = h * yl(z + d1z / 2);

		d3z = h * yll(t + h / 2, z + d2z / 2);
		d3y = h * yl(z + d2z / 2);

		d4z = h * yll(t + h, z + d3z);
		d4y = h * yl(z + d3z);

		y += d1y / 6 + d2y / 3 + d3y / 3 + d4y / 6;
		z += d1z / 6 + d2z / 3 + d3z / 3 + d4z / 6;
		t += h;
	}
}
int main()
{
	cout << fixed << setprecision(6);
	
	double h = 0.25, t = 0, y = 0, z = 1;
	euler(h, t, y, z);

	cout << endl << endl;

	RK4(h, t, y, z);
	system("pause");
	return 0;

}
