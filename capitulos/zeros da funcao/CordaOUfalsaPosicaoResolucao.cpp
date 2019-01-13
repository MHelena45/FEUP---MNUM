#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	float a = 1, b = 0.5, c = 0.5;
	return a * pow(x, 7) + b * x - c;
}
int main()
{
	/************************************************************/
	/*        M�todo da corda ou falsa posi��o ou secante       */
	/************************************************************/
	/*
		M�TODO INTERVALAR. Usa o intervalo xe e xd para arranque do processo iterativo.
		Este m�todo � mais r�pido que o m�todo da bisse��o
		O ponto b mant�m-se sempre fixo, e o ponto a fica sucessivamente mais perto da raiz real.


		No exemplo dado, o ponto xd mant�m-se 1.000 ao longo das sucessivas itera��es.
		O ponto xe e xn v�o se sempre alterar.
	*/

	//Intervalo inicial entre 0 e 1
	double xe = 0, xd = 1, xn;

	cout << fixed << setprecision(6); //Dado que C++ trunca os numeros em vez de arrendodar � melhor colocar uma casa decimal a mais

	cout << "xe" << setw(10) << "xd" << setw(10) << "xe" << endl;

	for (int i = 0; i < 4; i++)
	{
		xn = xd - (f(xd) / (f(xd) - f(xe))*(xd - xe));    //Apenas xn vai mudado, obdecendo a formula da recorr�ncia
		cout << xe << setw(10) << xd << setw(10) << xn << endl;
		xe = xn;											//Na proxima itera��o xe e o valor de xn na itera��o seguinte
	}

	system("pause");
	return 0;
}