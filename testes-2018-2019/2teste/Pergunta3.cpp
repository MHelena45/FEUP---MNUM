#include <iostream>
#include <iomanip>
using namespace std;

/***************************************/
/*            Regra Aurea              */
/***************************************/

double f(double x)
{
	return x + (pow(x - 2, 2) / (sin(x) + 2));
}
int main()
{
	cout << fixed << setprecision(6);

	double B = (sqrt(5) - 1) / 2; //numero de ouro
	double A = pow(B, 2);

	double x1 = -1, x2 = 1.5, x3, x4;
	x3 = A * (x2 - x1) + x1;
	x4 = B * (x2 - x1) + x1;
	cout << "x1 " << setw(10) << "x2" << setw(10) << "x3 " << setw(10) << "x4" << setw(12);
	cout << "fx1 " << setw(10) << "fx2" << setw(10) << "fx3 " << setw(10) << "fx4" << endl;
	for (int i = 0; i < 2; i++)
	{	
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
		cout << x1 << setw(10) << x2 << setw(10) << x3 << setw(10) << x4 << setw(10);
		cout << f(x1) << setw(10) << f(x2) << setw(10) << f(x3) << setw(10) << f(x4) << endl;
	}
	
	cout << "Amplitude : " << abs(x1 - x4) << endl;
	cout << "Amplitude : " << abs(x2 - x3) << endl;

	system("pause");
}