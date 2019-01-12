#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	return pow(x, 3) - 10 * sin(x) + 2.9;
}
int main() {

	 /**************************************/
	 /*          Método da Bisseção        */
	 /**************************************/
	
	//Intervalo inicial de 1.5 a 6.5
	double a = 1.5, b = 6.5;
	
	for (int i = 0; i < 2; i++)
	{
		//1 passo - Calculo do ponto medio do intervalo
		double pontoMedio = (a + b) / 2;

		if (!f(pontoMedio))   //encontramos o zero
			break;
		//2 passo - Escolher o sub-intervalo que contem a raiz que se pertende determinar
		if (f(pontoMedio) * f(a) < 0)
			b = pontoMedio;        //zero da funcao encontra-se entre a e o ponto medio
		else
			a = pontoMedio;       //zero da funcao encontra-se entre o ponto medio e b

		cout << "o zero encontra-se entre ["<< a << "," << b << "] sendo o ponto medio "<< pontoMedio <<endl ;
			
	}
	system("pause");
	return 0;
}