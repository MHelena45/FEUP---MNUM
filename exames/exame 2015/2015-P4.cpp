#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x)
{
  return 2 * log(2 * x);
}
int main()
{
	cout << fixed << setprecision(6);

	double xn1, xn = 1.1; //guess inicial
	cout << xn << endl;
	for (int i = 0; i < 1; i++)
	{
		xn1 = f(xn);
		cout << xn1 << endl;
		cout << "residuo: " << xn1 - xn << endl << endl;
		xn = xn1;
	}

	system("pause");
	return 0;

}
