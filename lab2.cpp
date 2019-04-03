#include"Lab2.h"
#include<math.h>
#include<malloc.h>
#include<iostream>
using namespace std;
unsigned N;
double *x_init, *y_init;

double Lagrange(double x, double *X,double *Y, int n )//n为插值节点数
{
	double L = 0;
	for (int i = 0; i < n; i++)
	{
		double L_fenzi = 1, L_fenmu = 1;
		for (int j = 0; j <= i - 1; j++)
		{
			L_fenzi *= x - X[j];
			L_fenmu *= X[i]- X[j];
		}
		for (int j = i+1; j <n; j++)
		{
			L_fenzi *= x - X[j];
			L_fenmu *= X[i] - X[j];
		}
		L += Y[i] * L_fenzi / L_fenmu;
	}
	return L;
	//cout << X[0] << "  " << Y[0] << endl;
}
void Init_Lagrange(double *&x,double *&y,unsigned n,double (*fx)(unsigned i,unsigned xn),double (*fy)(double))//n个节点
{
	x = (double*)malloc(sizeof(double)*n);
	y = (double*)malloc(sizeof(double)*n);
	//x = new double(n);
	//y = new double(n);
	for (unsigned i = 0; i < n; i++)
	{
		x[i] = fx(i,n);
		y[i] = fy(x[i]);
	}	//int *arr = new int[len];


}
double fx1(unsigned i, unsigned xn)//xn是插值节点/
{
		return -5 + 10 * (double)i / ((double)xn - 1);
}
double fx2(unsigned i, unsigned xn)//xn是插值节点
{
	return -5 * cos(PI*(2 * (double)i + 1) / (2 * ((double)xn - 1) + 2));
}
double fy(double x)
{
	return 1 / (4 + x + x * x);
}

double InAccuracy(double Lagrange(double x, double *X, double *Y, int n), double fy(double))
{
	double max = 0;
	for (int i = 0; i <= 500; i++)
	{
		double tmp = fabsl(Lagrange((double)i / 50 - 5,x_init,y_init,N+1) - fy((double)i / 50 - 5));
		if (max < tmp)
			max = tmp;
	}
	return max;
}



