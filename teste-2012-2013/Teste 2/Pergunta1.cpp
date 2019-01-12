#include <iostream>
#include <iomanip>
using namespace std;
/****Pergunta 1 a*/
/****************************/
/*******GAUSS-Jacobi*********/
/****************************/
int main() {
	//valores da iteracao anterior
	double an, bn, cn, dn;
	//valores desta iteracao
	double an1, bn1, cn1, dn1;
	int niteracoes = 1;
	//valores iniciais
	an = 0.25;
	bn = 0.25;
	cn = 0.25;
	dn = 0.25;
	while (niteracoes < 3)
	{
		cout << "x" << niteracoes << endl;;

		//com a expressao 4.5 * a - b -c +d = 1
		an1 = (1 + bn + cn - dn) / 4.5;

		//-a+4.5*b+c-d=-1
		bn1 = (-1 + an - cn + dn) / 4.5;

		//-a+2*b+4.5*c-d=-1
		cn1 = (-1 + an - 2 * bn + dn) / 4.5;

		//2*a-b-c+4.5*d=0;
		dn1 = (-2 * an + bn + cn) / 4.5;
	
		cout << "a  " << an1 << endl;
		cout << "b  " << bn1 << endl;
		cout << "c  " << cn1 << endl;
		cout << "d  " << dn1 << endl << endl;

		//alterando os valores para a proxima iteração
		an = an1;
		bn = bn1;
		cn = cn1;
		dn = dn1;
		niteracoes++;
	}
	 
	return 0;

}

/*****************************************************/
	/**  Pergunta 1-b ************/
	/*
	O metodo converge porque a matriz e diagonalmente dominante, isto e, em cada linha da matriz A, 
	o módulo do elemento da diagonal principal é superior ao modulo dos restantes elementos da linha respondente.
	*/



