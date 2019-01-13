#include <iomanip>
#include <iostream>
using namespace std;
double W(double x, double y)
{
	return -1.7 *x *y + 12 * y + 7 * x*x - 8 * x;

}
double Wlx(double x, double y)
{
	return -1.7 * y + 14 * x - 8;
}
double Wly(double x, double y)
{
	return -1.7 * x + 12;
}
int main()
{
	double xn1, xn = 2.4, yn1, yn = 4.3;
	double w;
	double h = 0.1;  
	for (int i = 0; i < 2; i++) {
		w = W(xn, yn);
		cout << "W(Xn) " << w << endl;
		cout << "Gradiente: " << endl;
		cout << Wlx(xn, yn) << endl;
		cout << Wly(xn, yn) << endl;
		int j = 0;
		while (true) { //ciclo termina quando W>0
			xn1 = xn - h * Wlx(xn, yn);
			yn1 = yn - h * Wly(xn, yn);
			if (W(xn1, yn1) > W(xn, yn))
				h /= 2; //se Z > 0 descarta-se outra vez o ponto e corta-se o passo ao meio
			else if(!j){
				h *= 2;
				break;
			}
				
		}
		/* LAMBDA */
		/* Apenas se usa o passo *efetivo* de minimização.	*/
		cout << "Lambda efetivo : " << h << endl << endl; //neste caso o lambda acaba por ficar 0.25
		xn = xn1;
		yn = yn1;
	}

	system("pause");
	return 0;
}