#include <iostream>
#include <iomanip>
using namespace std;
//double utiliza 14 casas decimais
double f(double x)
{
	return x + (pow((x - 2), 2)) / (sin(x) + 2);
}
int main()
{	
	cout << fixed << setprecision(8);
	double x1 = -1, x2 = 1.5; //Intervalo dado
	double fx1, fx2, fx3, fx4; //apesar de ocupar memoria, a complexidade temporal é mais importante

	double B = (sqrt(5) - 1) / 2; //numero Áureo
	double A = B * B;     //1 terço "perfeito"
	double x3 = A * (x2 - x1) + x1;     //Cálculo de x3
	double x4 = B * (x2 - x1) + x1;     //Cálculo de x4
	fx1 = f(x1);       fx2 = f(x2);		//menos calculos da funçao
	fx3 = f(x3);       	fx4 = f(x4);
	cout << "  x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "x4" << setw(15);
	cout << "f(x1)" << setw(15) << "f(x2)" << setw(15) << "f(x3)" << setw(15) << "f(x4)" << endl;
	for (int i = 0; i < 3; i++)
	{		
		cout << x1 << setw(15) << x2 << setw(15) << x3 << setw(15) << x4 << setw(15);
		cout << fx1 << setw(15) << fx2 << setw(15) << fx3 << setw(15) << fx4 << endl;
		if (fx3 < fx4)
		{
			x2 = x4;   			fx2 = fx4;
			x4 = x3;            fx4 = fx3;
			x3 = A * (x2 - x1) + x1;
			fx3 = f(x3);
		}
		else {
			x1 = x3;           			fx1 = fx3;
			x3 = x4;         			fx3 = fx4;
			x4 = B * (x2 - x1) + x1; 
			fx4 = f(x4);
		}
	}
	cout << endl << endl << "Amplitude " << (x2 - x1) << endl << endl;;
	system("pause");
	return 0;
}