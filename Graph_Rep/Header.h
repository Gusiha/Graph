#pragma once
#include <iostream>
#include <ctime>

using namespace std;

void Print(int** arr, int Dim)
{
	for (int i = 0; i < Dim; i++)
	{
		for (int j = 0; j < Dim; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void InitialCreating(int** arr, int &Dim, bool &Type)
{
	for (int i = 0; i < Dim; i++)
	{
		arr[i] = new int[Dim];
	}

	if (Type)
	{
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (i == j)
				{
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = rand() % 2;
					arr[j][i] = arr[i][j];
				}
			}
		}
	}

	else
	{
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Dim; j++)
			{
				arr[i][j] = rand() % 2;
			}
		}
	}

	Print(arr, Dim);
}
