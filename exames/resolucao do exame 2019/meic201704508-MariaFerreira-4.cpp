#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << fixed << setprecision(6);
	double T1, T2, T4, resultado;
	double hx=1, hy=1;
	T1 = 1.1 + 9.4 + 3 + 1.2;
	T2 = 1.4 + 2.1 + 2.2 + 1.5;
	T4 = 4.5;
	resultado = (hx / 2)*(hy / 2)*(T1 + (2 * T2) + 4 * T4);
	cout << resultado << endl;
	system("pause");
	return 0;

}