#include<iostream>

#include"lab2.h"
#include"lab3.h"
#include"lab4.h"
#include<malloc.h>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#define E 0.0000000001
using namespace std;
double fx(double x);
unsigned N;
int main()
{
	unsigned N ;
	for (int k = 0,N=1; k <= 12; k++)
	{

		double I = TiXin(fx, 1, 6, N);
		cout << setw(4) << N << "   " <<
			scientific << setprecision(12) << I << "   "
			<< cos(1) - cos(6) - I
			<< endl;
		N *= 2;
	}
	cout << endl;
	for (int k = 0, N = 1; k <= 12; k++)
	{

		double I = Simpson(fx, 1,6,N);
		cout << setw(4) << N << "   " <<
			scientific <<setprecision(12) << I<<"   "
			<<cos(1)-cos(6)-I
			<< endl;
		N *= 2;
	}
	//cout << scientific << setprecision(12) << Newton_Iteration(fx, 0, 0.000001) << endl;
	//cout << scientific << setprecision(12) << Newton_Iteration(fx, 1, 0.000001) << endl;
	//cout << scientific << setprecision(12) << XianJie_Iteration(fx, 0,0.1, 0.000001) << endl;
	//cout << scientific << setprecision(12) << XianJie_Iteration(fx, 0.5, 1.0, 0.000001) << endl;
}
double fx(double x)
{
	return sin(x);
}





/*
	ѧϰ�ʼǣ�
	1��c/c++��������Ƕ�׶���
	2��void f();f ��һ��ָ�룬ָ��һ�����������������ͷ���ֵ����void
	3,Ĭ�ϲ���ֻ�ܳ����������У������Գ����ڶ�����
	4,VS������鿴���ܣ�����һ������a����СΪ5����ֱ�Ӳ鿴"a,5"����
	5,cout���÷�����
	6,��� ���� �� InAccuracy
	7,new��delete�Ĺ��ܺ���

*/
