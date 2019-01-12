#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	cout << fixed << setprecision(6);

	double hx = 0.9;
	double hy = 0.9;

	//soma dos termos que se multiplicam por 1
	double S1 = 1.1 + 4.1 + 6.5 + 1.2;

	//soma dos termos que se multiplicam por 4
	double S2 = 1.4 + 2.1 + 2.2 + 1.5;

	//soma dos termos que se multiplicam por 16
	double S4 = 4.5;

	double resultado =((hx*hy) /9) *( S1 + 4 * S2 + 16 * S4);
	cout << "Resultado : " << resultado << endl;

	system("pause");
}