#include <iostream>
#include <iomanip>
using namespace std;
/*
Alinea A
No maxima
M : matrix([0.1,  0.5, 3, 0.25, 0],  [1.2, 0.2, 0.25, 0.2, 1],
				[-1 ,0.25, 0.3, 2, 2],[2,0.00001,1,0.4,3]);
echelon(M);
*/
int main()
{
	/* Alinea B */
	double x4 = 1.82038;
	double x3 = -1.41033 + 0.9541745134965474 * x4;
	double x2 = -0.1724137931034483 -6.163793103448276 * x3 - 0.4827586206896552*x4;
	double x1 = -5 * x2 - 30 * x3 - 2.5 * x4;
	cout << fixed << setprecision(6);
	cout << "x1 : " << x1 << endl;
	cout << "x2 : " << x2 << endl;
	cout << "x3 : " << x3 << endl;
	cout << "x4 : " << x4 << endl;
	system("pause");
}

/*Alinea B no maxima evitando matrizes

eq1: 0.1 * a + 0.5 *b + 3 *c +0.25*d = 0;
eq2 : 1.2 *a + 0.2 *b + 0.25 * c + 0.2 * d = 1;
eq3 : -1 * a + 0.25 * b + 0.3 *c + 2 *d =2
eq4 : 2*a+0.00001 *b +c +0.4 * d = 3
float(solve([eq1,eq2,eq3,eq4],[a,b,c,d]));
*/
/*Alinea C
Estabilidade externa
Sabendo que A está afetada por um erro de  0.5 e B tambem está afetada por um erro de 0.5.

 0.5 - (0.5 * (0.97265 - 3.0650 + 0.32663 + 1.82038));
 Os residuos das equacoes tem por isso o valor de 0.47267

 Resolvendo novamente a mesma matriz a com b = matrix([0.47267], [0.47267],[0.47267],[0.47267]);

 eq1: 0.1 * a + 0.5 *b + 3 *c +0.25*d = 0.47267;
 eq2 : 1.2 *a + 0.2 *b + 0.25 * c + 0.2 * d = 0.47267;
 eq3 : -1 * a + 0.25 * b + 0.3 *c + 2 *d =0.47267;
 eq4 : 2*a+0.00001 *b +c +0.4 * d = 0.47267;
 float(solve([eq1,eq2,eq3,eq4],[a,b,c,d]));
 */
