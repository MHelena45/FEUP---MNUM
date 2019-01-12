#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//Alinea b
	double h = 0.2;
	double Il =(h / 2) * (5 + 11.2 + 12.4 + 15.6 + 8.5);
	cout << Il << endl;

	//Alinea C

	double I = 5.18,Ill = 5.235;
	double Qc = (Il - I) / ( Ill- Il);
	cout << "Qc = " << Qc << endl;

	/*Alinea d
	Nao o valor do quociente de convergência não se aproxima de 4, 
	logo não garante uma boa aproximação do integral
	*/

	//alinea e
	double erro = abs((Ill - Il) / 3);
	cout <<"erro = " << erro << endl;

	return 0;
}