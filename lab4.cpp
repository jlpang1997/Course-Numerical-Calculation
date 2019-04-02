#include"lab4.h"
#include<math.h>
#include<iostream>
#include<iomanip>
using namespace std;
double Newton_Iteration(double(*fx)(double x),double x0,double e)
{
	double x = x0;
	int k = 0;
	while (fabs(fx(x)) > e)
	{
		cout << setw(2)<<k<<scientific<<setprecision(12) << "  " << x << "  " << fx(x) << endl;
		x = x - fx(x) / WeiFen(fx, x);
		k++;
	}
	cout << setw(2) << k << scientific << setprecision(12) << "  " << x << "  " << fx(x) << endl;
	return x;
}
double XianJie_Iteration(double (*fx)(double x),double x0,double x1,double e)
{
	int k =0;
	while (fabs(fx(x0)) > e)
	{
		cout << setw(2) << k << scientific << setprecision(12) << "  " << x0 << "  " << fx(x0) << endl;
		double tmp = x1;
		x1 = x1 - fx(x1)*(x1 - x0) / (fx(x1) - fx(x0));
		k++;
		x0 = tmp;
	}
	cout << setw(2) << k << scientific << setprecision(12) << "  " << x0 << "  " << fx(x0) << endl;
	return x0;
}
double WeiFen(double(*fx)(double x), double x0, double h)
{
	return (fx(x0 + h) - fx(x0)) / h;
}