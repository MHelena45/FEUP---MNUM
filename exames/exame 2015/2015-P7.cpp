#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x)
{
  return pow(x,3) - 10 *sin(x) + 2.8;
}

int main()
{
	cout << fixed << setprecision(6);
	double a = 1.5, b = 4.2, m;
	for (int i = 0; i < 3; i++)
	{
		m = (a + b) / 2;
		cout << i << setw(20) << b << endl;
		if (f(a)*f(m) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}
	cout << endl;

	system("pause");
	return 0;

}
