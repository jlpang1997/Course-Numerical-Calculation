#include<iostream>
#include<iomanip>
//实验
#include"lab2.h"
#include"lab3.h"
#include"lab4.h"
//测试函数
#include"fx.h"

#define E 0.0000000001//误差
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
	学习笔记：
	1，c/c++不允许函数嵌套定义
	2，void f();f 是一个指针，指向一个函数，函数参数和返回值都是void
	3,默认参数只能出现在声明中，不可以出现在定义中
	4,VS的数组查看功能，比如一个数组a，大小为5，则直接查看"a,5"即可
	5,cout的用法很迷
	6,误差 翻译 ： InAccuracy
	7,new和delete的功能很迷

*/
