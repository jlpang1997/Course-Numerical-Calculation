#include<iostream>
#include<iomanip>
//ʵ��
#include"lab2.h"
#include"lab3.h"
#include"lab4.h"
//���Ժ���
#include"fx.h"

#define E 0.0000000001//���
using namespace std;

int main()
{
	for (int k = 0,N=1; k <= 12; k++)
	{

		double I = TiXin(fx, 1, 6, N);
		double I_precise = cos(1) - cos(6);
		cout << setw(4) << N << "   " <<
			scientific << setprecision(12)
			<< I << "   "
			//<< I_precise << "   "
			<< I_precise - I << endl;
		N *= 2;
	}
	cout << endl;
	for (int k = 0, N = 1; k <= 12; k++)
	{
		double I = Simpson(fx, 1, 6, N);
		double I_precise = cos(1) - cos(6);
		cout << setw(4) << N << "   " <<
			scientific << setprecision(12)
			<< I << "   "
			//<< I_precise << "   "
			<< I_precise - I << endl;
		N *= 2;
	}
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
