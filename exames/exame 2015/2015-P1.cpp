#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double T(double Tn)
{
	int Ta = 37;
	return -0.25*(Tn - Ta);
}
int main()
{
	cout << fixed << setprecision(6);

	double Tn = 3, t = 5, h = 0.4;
	for (int i = 0; i < 2; i++)
	{
		Tn += h * T(Tn);
		t = 5 + h;		
	}
	cout << Tn << endl;
	system("pause");
	return 0;

}