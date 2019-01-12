#include <iostream>
#include <iomanip>
using namespace std;
double fl(double yl) { 
	return yl; 
}

double fll(double t, double yl) { 
	double A = 1.5;
	return (A + pow(t,2) + t * yl);
}

void mEuler(double tn, double yn, double yln, double h, unsigned int num_iter) {

	double tn1, yn1, yln1;

	cout << "n" << setw(10) << "t" << setw(10) << "y" << endl;
	cout << "0" << setw(10) << tn << setw(10) << yn << endl;
	for (unsigned int i = 1; i <= num_iter; i++) {
		yln1 = yln + h * fll(tn,yln);
		yn1 = yn + h * fl( yln);
		tn1 = tn + h;

		yln = yln1;
		yn = yn1;
		tn = tn1;
		
		cout << i << setw(10) << tn << setw(10) << yn << endl;
	}
}

void RK4(double t, double y, double yl , double h, unsigned int num_iter)
{
	double dy1, dy2, dy3, dy4;
	double dyl1, dyl2, dyl3, dyl4;

	cout << "n" << setw(10) << "t" << setw(10) << "y" << endl;
	cout << "0" << setw(10) << t << setw(10) << y << endl;

	for (unsigned int i = 1; i <= num_iter; i++)
	{
		dy1 = h * fl(yl);
		dyl1 = h * fll(t, yl);

		dy2 = h * fl( yl + (dyl1 / 2));
		dyl2 = h * fll(t + h/2, yl + (dyl1 / 2));

		dy3 = h * fl( yl + (dyl2 / 2));
		dyl3 = h * fll(t + h / 2, yl + (dyl2 / 2));

		dy4 = h * fl( yl + dyl3);
		dyl4 = h * fll(t + h , yl + dyl3);
		
		y += (dy1 / 6) + (dy2 / 3) + (dy3 / 3) + (dy4 / 6);
		yl += (dyl1 / 6) + (dyl2 / 3) + (dyl3 / 3) + (dyl4 / 6);
		t += h;

		cout << i << setw(10) << t << setw(10) << y << endl;
	}

}

int main()
{
	cout << fixed << setprecision(6);

	double h = 0.2, t = 1, y = 0, yl = 1;
	unsigned int num_iter = 2;

	cout << "Metodo de euler" << endl << endl;
	mEuler(t, y, yl , h, num_iter);

	cout << endl << "Metodo de Runge-Kutta" << endl << endl;
	RK4(t, y, yl, h, num_iter);

	system("pause");

	return 0;
}