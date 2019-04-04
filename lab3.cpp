#include"lab3.h"
#include<math.h>
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
double wucha(double(*fx)(double x),bool flag, unsigned N)
{
	if (flag == false)//ÌÝÐÎ
	{
		double I = cos(1) - cos(6);
		double E = I-TiXin(fx, 1, 6, N);
		double En = I-TiXin(fx, 1, 6, 2 * N);
		return -log(En / E) / log(2);

	}
	else {//simpson
		double I = cos(1) - cos(6);
		double E = I - Simpson(fx, 1, 6, N);
		double En = I - Simpson(fx, 1, 6, 2 * N);
		return -log(En / E) / log(2);
	}
}
//²âÊÔ´úÂë
//for (int k = 0, N = 1; k <= 12; k++)
//{
//
//	double I = TiXin(fx, 1, 6, N);
//	double I_precise = cos(1) - cos(6);
//	cout << setw(4) << N << "   " <<
//		scientific << setprecision(12)
//		<< I << "   "
//		//<< I_precise << "   "
//		<< I_precise - I << "   "
//		<< wucha(fx, false, N) << endl;
//	N *= 2;
//}
//cout << endl;
//for (int k = 0, N = 1; k <= 12; k++)
//{
//	double I = Simpson(fx, 1, 6, N);
//	double I_precise = cos(1) - cos(6);
//	cout << setw(4) << N << "   " <<
//		scientific << setprecision(12)
//		<< I << "   "
//		<< I_precise - I << "   "
//		<< wucha(fx, true, N) << endl;
//	N *= 2;
//}