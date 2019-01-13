#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
	return (x - 2.6) + pow(cos(x + 1.1), 3);
}

//recomendo por no maxima com a linha
//diff((x - 2.6) + cos(x + 1.1)^ 3,x,1);
double fl(double x)
{
	return 1 - 3 * pow(cos(x + 1.1), 2) * sin(x + 1.1);
}
int main()
{
	/*********************************************/
	/*              Metodo de Newton             */
	/*********************************************/
	/*
		Método não intervalar
		usa apenas 1 ponto para o arranque do processo iterativo x0.
		Nota: quando o ponto inicial não os é dado, devemos lançar o algoritmo de diferentes valores iniciais.
	
	*/
	double xn = 1.8; //sendo inicialmente x0
	double xn1 = xn - f(xn) / fl(xn); //formula de recorrencia

	//Bom exemplo do porque se usar ua precisisao acima da pedida,
	//Ao correr o programa com a precisao 5, daria-nos 7.10525 em vez de 7.10526 resposta correta
	cout << fixed << setprecision(6);

	cout << xn1 << endl;

	system("pause");
	return 0;
}