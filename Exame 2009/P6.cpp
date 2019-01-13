#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	/* Aplicando a regra dos trapezios */
	double s = 5 + 11.2 + 12.4 + 15.6 + 8.5;
	s *= (0.2 / 2);
	cout << "Qc = " << (s - 5.18) / (5.235 - s) << endl;
	/* Alinea C
		Nao porque nao se aproxima de 2^ordem = 4
	*/
	cout << "erro = " << (5.27 - 5.235) / 3 << endl;
	system("pause");
	return 0;
}