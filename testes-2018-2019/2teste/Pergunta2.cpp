#include <iomanip>
#include <iostream>
using namespace std;
double fl(double t, double x, double z)
{
	return z;
}
double fll(double t, double x, double z)
{
	int m = 20, c = 1;
	//int k = 5; k = 20; //opcoes das escolhas multiplas
	int k = 40;
	return( -c * z - k * x) / m;
}
int main()
{
	double h = 0.1; //havendo 5 ponto entre 0 e 0.5, o passo de integração e 0.1
	double t = 0;
	double x = 1;
	double z = 0;
	cout << "t" << setw(10) << "x" << endl << endl;
	while (t < 5) {

		cout << t << setw(10) << x << endl;
		x += h * fl(t, x, z);
		z += h * fll(t, x, x);
		t += h;
	}
	system("pause");
	return 0;
}
