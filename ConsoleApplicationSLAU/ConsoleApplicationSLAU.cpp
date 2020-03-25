#include <iostream>

#include <stdio.h>

using namespace std;

int main()
{
	const int N = 4;
	int n = 0;
	double A[N][N], b[N], L[N][N], U[N], x1[N], x, z = 0, D = 0;

	cin >> n;

	// ввод матрицы
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	// ввод значений для x1, x2, x3, x4 
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (int s = 1; s < n; s++)
	{
		for (int i = s; i < n; i++)
		{
			x = A[i][s - 1];

			A[i][s - 1] = x / A[s - 1][s - 1];

			for (int j = s; j < n; j++)
			{
				A[i][j] = A[i][j] - (A[s - 1][j] * A[i][s - 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				L[i][j] = 1;
			}

			if (i < j)
			{
				L[i][j] = 0;
			}

			if (i > j)
			{
				L[i][j] = A[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		z = 0;

		for (int j = 0; j < i; j++)
		{
			z = z + U[j] * L[i][j];
		}

		U[i] = b[i] - z;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		z = 0;

		int j;

		for (j = n - 1; j > i; j--)
		{
			z = z + x1[j] * A[i][j];
		}

		x1[i] = (U[i] - z) / A[i][j];
	}

	// находим детерминант
	for (int i = 0; i < n; i++)
	{
		D = D + A[i][i];
	}

	// вывод значений x1, x2, x3, x4 и детерминант
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << " = " << x1[i] << endl;
	}

	cout << "\n" << "D = " << D;
}

