#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	double c = 1.5;
	return exp(c * x);
}
double simpson(double h)
{
	//intervalo de integração de a  a b
	double a = 2.5, b = 3;
	double Is = f(a) + 4 * f(a + h) + 2 * f(a + 2*h) + f(b);
	Is *= (h / 3);
	cout << "Para h = "<< h << " o resultado e " << Is << endl;
	return Is;
}

void Qc(double I, double Il, double Ill)
{
	//Qc deve se aproximadamente de 16
	cout <<"Qc = " << (Il - I) / (Ill - Il) << endl;
}
void erro(double Il, double Ill)
{
	//estimativa para o erro cometido em Ill simp
	cout << "erro = " <<  (Ill - Il)/15 << endl;
}
int main()
{
	
	double h = 0.125;
	/*
	Dado que 0.5 / 0.125 = 4 que é um número par, a regra de simpson pode ser efetuada 
	*/
	double I, Il, Ill;
	I = simpson(h);
	Il = simpson(h/2);
	Ill = simpson(h/4);
	Qc(I, Il, Ill);
	erro(Il, Ill);
	cout << "O valor de I= " << I << endl;
	system("pause");
	return 0;
}