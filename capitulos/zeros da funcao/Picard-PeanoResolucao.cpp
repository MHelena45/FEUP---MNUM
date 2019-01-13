#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double g(double x)
{
	return 1/tan(x)*sin(3 * x) - 4.8;
}
/*
No maxima com
diff(cot(x)*sin(3*x)-4.8,x);

*/
double gl(double x)
{
	return abs(3 * (1 / tan(x))*cos(3 * x) - pow(1 / sin(x), 2)*sin(3 * x));
}

int main()
{
	/***************************************************/
	/*              Metodo de Picard-Peano             */
	/***************************************************/
	/*
		Método não intervalar
		usa apenas 1 ponto para o arranque do processo iterativo x0.
		x1= g(x0) designado guess. E este x1 sera o ponto de partida para o proximo guess.
		x2 = g(x1)
		...
		xn+1 = g(xn)

		Nota: quando o ponto inicial não os é dado, devemos lançar o algoritmo de diferentes valores iniciais.

		Inicialmente verificamos a condição de convergência.
		| gl(x)| < 1
	*/

	cout << "Condicoes de convergencia \n \n";
	
	cout << "Hipotese 1 \n";
	cout << gl(5.3) << setw(10) << " e " << gl(5.7) << endl << endl;

	cout << "Hipotese 2 \n";
	cout << gl(6.6) << setw(10) << " e " << gl(7) << endl << endl;

	cout << "Hipotese 3 \n";
	cout << gl(2.5) << setw(10) << " e " << gl(2.9) << endl << endl;

	cout << "Hipotese 6 \n";
	cout << gl(4.6) << setw(10) << " e " << gl(5) << endl << endl;

	cout << "Hipotese 7 \n";
	cout << gl(3.7) << setw(10) << " e " << gl(4) << endl << endl;

	cout << "Como podemos ver nos resulatados obtidos, so com a hipotese 6 é que se verifica a condicao de convegencia" << endl;
	
	return 0;
}