#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x)
{
	return x* 2;
}
int main()
{
	cout << fixed << setprecision(6);
	float x, x0 = 2, xf = 14, c = 2, n= 6;

	for (float x = x0; x <= xf; x += c)
	{
		cout << f(x) << endl;
	}
	cout << endl << endl;
	//(xf -x0 )/ c = n
	for (int i = 0; i <= n; i++)
	{
		cout << f(x0 + i *c) << endl;
	}
	system("pause");
	return 0;

}
