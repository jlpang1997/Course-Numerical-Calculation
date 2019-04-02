#include"lab3.h"
double TiXin(double(*fx)(double x), double start, double end, unsigned N)
{
	double h = (end - start) / N;
	double I = 0;
	for (int i = 1; i < N - 1; i++)
	{
		I += fx(start + h * i);
	}
	I += (fx(start) + fx(end)) / 2;
	I *= h;
	return I;

}
double Simpson(double(*fx)(double x), double start, double end, unsigned N)
{
	double h = (end - start) / N;
	signed m = N / 2;
	double I = 0;
	for (int i = 0; i < m - 1; i++)
	{
		I += 4 * fx(start + (2 * i + 1)*h);
	}
	for (int i = 1; i < m - 1; i++)
	{
		I += 2 * fx(start + 2 * i*h);
	}
	I += fx(start) + fx(end);
	I *= h / 3;
	return I;
}
