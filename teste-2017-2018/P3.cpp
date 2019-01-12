#include <iostream>
using namespace std;

/*********************************/
/*      Regra dos Trap�zios      */
/*********************************/
/* 
	 Divide-se o intervalo de integra��o [a, b] em n sub-intervalos igualmente espa�ados de
	 amplitude h ( passo de integra��o) 
*/
int main() {

	//menor passo de integra��o (0.2)
	double h = 0.2;
	double soma = 1.16 + 2 * (0.45 + 1.08 + 0.53 + 0.65 + 1.32 + 1.24 + 1.18) + 0.42;
	double Ill = (h / 2) *soma;
	cout << "resultado " << Ill << endl;

	//com passo de integra��o de 0.4
	h = 0.4;
	soma = 1.16 + 2 * ( 1.08 + 0.65 + 1.24 ) + 0.42;
	double Il = (h / 2) * soma;

	//com passo de integra��o de 0.8
	h = 0.8;
	soma = 1.16 + 2 * 0.65 + 0.42;
	double I = (h / 2) * soma;

	//erro estimado
	double erro = (Ill - Il) / 3;
	cout << "erro : " << erro << endl;

	double Qc = (Il - I) / (Ill - Il);
	cout << "Qc : " << Qc << endl;

	system ("pause");
}