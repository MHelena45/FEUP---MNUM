#include <iostream>
#include <iomanip>
using namespace std;
double Z(double x, double y)
{
	return 6 * x*x - x * y + 12 * y + y * y - 8 * x;
}
double Zlx(double x, double y)
{
	return 12 * x - y - 8;
}
double Zly(double x, double y)
{
	return -x + 12 + 2 * y;
}
int main()
{
	double xn1, xn = 0, yn1, yn = 0;
	double z = Z(xn, yn);
	cout << "Z(Xn) " << z << endl;
	cout << "Gradiente: " << endl;
	cout << Zlx(xn, yn) << endl;
	cout << Zly(xn, yn) << endl;

	double h = 1;  //Inicialmente lambda é igual a 1.

	while (true) { //ciclo termina quando Z>0

		xn1 = xn - h * Zlx(xn, yn);
		yn1 = yn - h * Zly(xn, yn);
		if (Z(xn1, yn1) > Z(xn, yn) )
			h /= 2; //se Z > 0 descarta-se outra vez o ponto e corta-se o passo ao meio
		else break;
	}	
	/* LAMBDA */
	/* Apenas se pôe o passo *efetivo* de minimização.	*/
	cout << "Lambda efetivo : " << h << endl; //neste caso o lambda acaba por ficar 0.25
	z = Z(xn1, yn1);
	cout << "x : "<< xn1 << endl << "y : " << yn1 << endl;
	cout << "Z(Xn) " << z << endl;
	cout << "Gradiente: " << endl;
	cout << Zlx(xn1, yn1) << endl;
	cout << Zly(xn1, yn1) << endl;

	system("pause");
	return 0;
}
