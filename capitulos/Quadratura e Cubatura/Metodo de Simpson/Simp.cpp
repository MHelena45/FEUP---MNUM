#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double SI(double h)
{
	double s4, res;
	s4 = 1.15;
	res = (h / 3)*(0.36 + 0.6 + s4 * 4);
	return res;
}
double SIl(double h)
{
	double s2, s4, res;
	s4 = 1.32 + 0.12;
	s2 = 1.15;
	res = (h / 3)*(0.36 + 0.6 + s4 * 4 + 2 * s2);
	return res;
}
double SIll(double h)
{
	double s2, s4,res;	
	s4 = 1.19 + 0.21 + 1.39 + 1.22;
	s2 = 1.32 + 1.15 + 0.12;
	res = (h / 3 )* (0.36 + 0.60 + s2 * 2 + s4 * 4);
	cout << res << endl;
	return res;
}
int main()
{
	//precisão dos resultados mostrados, não dos calculos intermedios
	cout << fixed << setprecision(8);
	double h = 0.25;
	double Ill = SIll(h);
	double Il = SIl(h * 2);
	double I = SI(h * 4);
	double erro = (Ill - Il) / 15;
	cout << "erro : " << erro << endl;
	system("pause");
	return 0;
}

