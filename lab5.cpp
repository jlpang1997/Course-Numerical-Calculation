#include"lab5.h"
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void Jacobi_Iteration(double A[][N], double b[N], double X[N], int n)
{
	double G[N][N];
	double g[N];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = -A[i][j] / A[i][i];
			}
		}
		g[i] = b[i] / A[i][i];
	}
	double max;
	int k = 0;
	do
	{
		k++;
		double X_tmp[N];
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += G[i][k] * X[k];
			}
			X_tmp[i] = sum + g[i];
		}
		max = 0;
		for (int i = 0; i < n; i++)//
		{
			double tmp = fabs(X[i] - X_tmp[i]);
			if (tmp > max)
				max = tmp;
			X[i] = X_tmp[i];
		}
	}while (max >= 0.00001);
	cout << k << endl;
}



void Gauss_Seidel_Iteration(double A[][N], double b[N], double X[N], int n)
{
	double G[N][N];
	double g[N];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = -A[i][j] / A[i][i];
			}
		}
		g[i] = b[i] / A[i][i];
	}
	double max;
	int k = 0;
	do
	{
		k++;
		double X_tmp[N];
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int k = 0; k < n; k++)
			{
				if(k>=i)
				{ 
					sum += G[i][k] * X[k];
				}
				else
					sum += G[i][k] * X_tmp[k];
			}
			X_tmp[i] = sum + g[i];
		}
		max = 0;
		for (int i = 0; i < n; i++)//
		{
			double tmp = fabs(X[i] - X_tmp[i]);
			if (tmp > max)
				max = tmp;
			X[i] = X_tmp[i];
		}
	} while (max >= 0.00001);
	cout << k << endl;
}









void main_lab5()
{
	double X[N] = { 0 };
	FILE *fp;
	fp = fopen("test_lab5.txt", "r");
	if (!fp)
	{
		printf("file open failed.");
		exit(0);
	}
	int n;
	double A[N][N];
	double b[N];
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int m;
			fscanf(fp, "%d", &m);
			A[i][j] = m;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		fscanf(fp, "%d", &m);
		b[i] = m;
	}
	fclose(fp);





	Jacobi_Iteration(A, b, X,n);
	for (int i = 0; i < n; i++)
	{
		cout << scientific << setprecision(12) << X[i] << endl;
	}
	cout << endl;
	cout << "******************************" << endl;

	for(int i=0;i<n;i++)
	{
		X[i] = 0;
	}

	Gauss_Seidel_Iteration(A, b, X, n);
	for (int i = 0; i < n; i++)
	{
		cout << scientific << setprecision(12) << X[i] << endl;;
	}
	cout << endl;

}

