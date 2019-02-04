#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Alinea A
//No Maxima
//M: matrix([1,1/2,1/3,-1],[1/2,1/3,1/4,1], [1 / 3, 1 / 4, 1 / 5, 1]);
//Para triangularizar a matriz:
//echelon(M);

//Alinea B
int main()
{
	cout << fixed << setprecision(6);

	double x, y;
	double z = -30;
	y = 18 - z;
	x = - 1 - (0.5 * y) - (0.333333333333333333333* z);
	cout << "x1 = " << x << endl;
	cout << "x2 = " << y << endl;
	cout << "x3 = " << z << endl << endl;

	cout << "Alinea C" << endl;
	//0.05-0.05*(-15)-0.05*(48)-0.05*(-30);
	//M: matrix([1,1/2,1/3,-0.1],[1/2,1/3,1/4,-0.1],[1 / 3, 1 / 4, 1 / 5, -0.1]);
	//echelon(M);

	double dx, dy, dz;
	dz = -3;
	dy = -0.6 - dz;
	dx = -0.1 - 0.5 * dy - 0.3333333333333 * dz;

	cout << "dx1 = " << dx << endl;
	cout << "dx2 = " << dy << endl;
	cout << "dx3 = " << dz << endl;

	system("pause");
	return 0;

}
