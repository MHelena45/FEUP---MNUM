#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x)
{
	return (x - 3.7) + pow(cos(x + 1.2), 3);
}
double fl(double x)
{
	return 1 - 3 * pow(cos(x + 1.2), 2)*sin(x + 1.2);
}
int main()
{
	cout << fixed << setprecision(7);
	double x = 3.8;
	double x1 = x - f(x) / fl(x);
	cout << x1 << endl;
	system("pause");
	return 0;

}
