#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double hx = 0.8;  //passo de integracao em x
	double hy = 0.8;  //passo de integracao em y

	double T1 = 1.1 + 3.5 + 2.4 + 1.2;
	double T2 = 1.4 + 2.1 + 2.2 + 1.5;
	double T4 = 1.5;

	double resultado =(hx / 2)*(hy/2)*( T1 + 2 * T2 + 4 * T4);
	cout << resultado << endl;
	system("pause");
	return 0;
}