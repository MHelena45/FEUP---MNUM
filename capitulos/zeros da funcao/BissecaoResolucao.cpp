#include <iomanip>
#include <iostream>
using namespace std;
double f(double x)
{
	return pow(x, 3) - 10 * sin(x) + 2.9;
}
int main()
{
	/*****************************************/
	/*          Metodo da Bisseção           */
	/****************************************/
	/*
		Método intervalar - Parte de um intervalo ]a,b[ para o arranque do processo iterativo. O intervalo contem apenas uma raiz da funçao, isto é,
		um zero da função necessariamente continua nesse intervalo.
	*/
	double a = 1.5, b=6.5; //intervalo é nos dado
	double pontoMedio; //ponto medio
	for (int i = 0; i < 2; i++) //citerio de numero de iterações
	{
		/* 1 passo - Calculo do ponto medio do intervalo
		*/
		pontoMedio = (a + b) / 2;

		/* 2 passo - Escolher o sub-intervalo que contem a raiz que se pertende 
		determinar
		*/
		if (!f(pontoMedio)) //encontramos o zero
			break;
		else if (f(pontoMedio)*f(a) < 0) //se f(a) tiver sinal contrario de f(pontoMedio) entao existe pelo menos 1 zero nesse intervalo
			b = pontoMedio;

		else a = pontoMedio; //o zero encontra-se ente b e o ponto medio
	
		cout << "O zero encontra-se entre ]" << a << "," << b << "]" << endl;
		
		/*repetir os passos 1 e 2*/
	}

	cout << "O zero e " << pontoMedio << endl;
	system("pause");
	return 0;
}