#pragma once
#include <iostream>
#include <ctime>

using namespace std;

// Global Variables (Graph Information)
int Dim;
bool Type;
int Max_Degree;

// Functions
int Find_Degree(int** arr)
{
	int count = 0;
	int max_count = 0;
	for (int i = 0; i < Dim; i++)
	{
		if (max_count < count) { max_count = count; }
		count = 0;
		for (int j = 0; j < Dim; j++)
		{
			if (count != 0) { count++; }
		}
	}
	return max_count;
}

void Print(int** arr)
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

int** InitialCreating(int** arr)
{
	for (int i = 0; i < Dim; i++)
	{
		arr[i] = new int[Dim];
	}

	// Неориентированный граф
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

	// Ориентированный граф
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

	return arr;
}

