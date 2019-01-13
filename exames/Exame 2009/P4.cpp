#include <iomanip>
#include <iostream>
using namespace std;
double f(double x)
{
	return 5 * cos(x) - sin(x);
}
int main()
{
	double x1 = 2, x2 = 4, x3, x4;
	double A, B;
	B = (sqrt(5) - 1) / 2;
	A = pow(B,2);   //ou B*B
	x3 = A * (x2 - x1) + x1;
	x4 = B * (x2 - x1) + x1;
	cout << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "x4" << setw(15)
		<< "f(x1)" << setw(15) << "f(x2)" << setw(15) << "f(x3)" << setw(15) << "f(x4)" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << x1 << setw(15) << x2 << setw(15) << x3 << setw(15) << x4 << setw(15)
			<< f(x1) << setw(15) << f(x2) << setw(15) << f(x3) << setw(15) << f(x4) << endl;
		if (f(x3) < f(x4))
		{
			x2 = x4;
			x4 = x3;
			x3 = A * (x2 - x1) + x1;
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = B * (x2 - x1) + x1;
		}
	}
	cout << endl << "Amplitude : " << abs(x1 - x2) << endl;
	system("pause");
	return 0;
}