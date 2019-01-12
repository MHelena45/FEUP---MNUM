#include <iomanip>
#include <iostream>
using namespace std;

/*********************************************/
/*          Método de Gauss-Seidel           */
/*********************************************/
/*
Inicialmente verificamos que a matriz é diagonalmente dominante, isto é, que o módulo de cada elemento
da diagonal principal é superior à soma dos módulos dos restantes elementos da linha correspondente

*/
int main()
{
	//inicialzados com os valores iniciais
	double an = 1.67969, bn = -1.7816, cn = 1.93752, dn = 2.10369;
	double an1, bn1, cn1, dn1;
	for (int i = 0; i < 2; i++) {

		cout << "x" << i << endl;
		cout << an << setw(10) << bn << setw(10) << cn << setw(10) << dn << endl;

		//6*a+0.5*b+3*c+0.25*d = 19
		an1 = (19 - 0.5 *bn - 3 * cn - 0.25*dn) / 6;

		//1.2*a+3*b+0.25*c+0.2*d = -2.2
		bn1 = (-2.2 - 1.2 * an1 - 0.25 * cn - 0.2 *dn) / 3;

		//-a + 0.25 * b + 4 * c + 2 *d = 9
		cn1 = (9 + an1 - 0.25 * bn1 - 2 * dn) / 4;

		//2 * a + 4 *b + c +8 * d = 15
		dn1 = (15 - 2 * an1 - 4 * bn1 - cn1) / 8;
		
		//preparar para a iteração seguinte
		an = an1; bn = bn1; cn = cn1; dn = dn1;
	}
	system("pause");
}