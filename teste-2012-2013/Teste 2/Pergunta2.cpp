#include <iostream>
#include <iomanip>
using namespace std;
/*funçao dada para a funcao derivada */
double f(double t, double x) {
	int a = 2, b = 2;
	return sin(a * x) + sin(b * t);
}
void alineaA()
{
	/*** 3intregacao */

	/*  valores iniciais    */
	double t = 1, x = 1;

	// h é o passo de integracao, vendo se pelo aumento de t 
	double h = 0.125;

	cout << "t " << setw(10) << " x " << endl;
	cout << t << setw(10) << x << endl;


	while (t < 1.5) {
		double dx1 = h * f(t, x);
		double dx2 = h * f(t + h / 2, x + (dx1 / 2));
		double dx3 = h * f(t + h / 2, x + (dx2 / 2));
		double dx4 = h * f(t + h, x + dx3);

		x += dx1 / 6 + dx2 / 3 + dx3 / 3 + dx4 / 6;

		//soma do valor anterior (inicial na 1 iteracao) com o passo de integração
		t += h;

		cout << t << setw(10) << x << endl;
	}
}
void alineaB()
{
	double I = 1.501855;
	double Il = 1.511739;
	double Ill = 1.51222;
	double Qc = (Il - I) / (Ill - Il);
	cout << "O quociente de convergencia e : " << Qc << endl;
}
int main() {

	//altera a precisao do valor de output
	cout << fixed << setprecision(8);
	cout << "Alinea A : " << endl << endl;
	alineaA();

	cout << endl << "Alinea B : " << endl;
	alineaB();

	system("pause");
	return 0;
}

/*   Alinea C
Dado que o quociente de convergencia é superior 2^ordem = 2^4 = 16 (pois é aproximadamente 20), 
nao garantimos que o resultado é uma boa aproximação ao valor exato.
Devias portanto diminuir o intervalo de integração para metade até o 
quociente de convergencia se igual ou inferior a 16,
*/



