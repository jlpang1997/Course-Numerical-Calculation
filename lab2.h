#pragma once
#define PI 3.1415926
//#define N 4// NÎª½×Êý=xn-1
extern double *x_init, *y_init;

extern unsigned N;
double Lagrange(double x, double *X = x_init, double *Y = y_init, int n = N + 1);

void Init_Lagrange(double *&x, double *&y, unsigned n, double(*fx)(unsigned i, unsigned xn), double(*fy)(double));

double fx1(unsigned i, unsigned xn);
double fx2(unsigned i, unsigned xn);//fx1 and fx2 is used to cout x[i];
double fy(double x);
double InAccuracy(double Lagrange(double x, double *X , double *Y , int n ), double fy(double));

