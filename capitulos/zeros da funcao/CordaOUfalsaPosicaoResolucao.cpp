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
	/*        Método da corda ou falsa posição ou secante       */
	/************************************************************/
	/*
		MÉTODO INTERVALAR. Usa o intervalo xe e xd para arranque do processo iterativo.
		Este método é mais rápido que o método da bisseção
		O ponto b mantém-se sempre fixo, e o ponto a fica sucessivamente mais perto da raiz real.


		No exemplo dado, o ponto xd mantém-se 1.000 ao longo das sucessivas iterações.
		O ponto xe e xn vão se sempre alterar.
	*/

	//Intervalo inicial entre 0 e 1
	double xe = 0, xd = 1, xn;

	cout << fixed << setprecision(6); //Dado que C++ trunca os numeros em vez de arrendodar é melhor colocar uma casa decimal a mais

	cout << "xe" << setw(10) << "xd" << setw(10) << "xe" << endl;

	for (int i = 0; i < 4; i++)
	{
		xn = xd - (f(xd) / (f(xd) - f(xe))*(xd - xe));    //Apenas xn vai mudado, obdecendo a formula da recorrência
		cout << xe << setw(10) << xd << setw(10) << xn << endl;
		xe = xn;											//Na proxima iteração xe e o valor de xn na iteração seguinte
	}

	system("pause");
	return 0;
}