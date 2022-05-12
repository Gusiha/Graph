#pragma once
#include <iostream>
#include <ctime>

using namespace std;

struct AdjacencyMatrix
{
	int Dim;
	bool Orientation;
	int** Adj_Matrix;
	
	void Print()
	{
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Dim; j++)
			{
				cout << Adj_Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Creating()
	{
		for (int i = 0; i < Dim; i++)
		{
			Adj_Matrix[i] = new int[Dim];
		}

		if (Orientation)
		{
			for (int i = 0; i < Dim; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (i == j)
					{
						Adj_Matrix[i][j] = 0;
					}
					else
					{
						Adj_Matrix[i][j] = rand() % 10;
						Adj_Matrix[j][i] = Adj_Matrix[i][j];
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
					if (i == j)
					{
						Adj_Matrix[i][j] = 0;
					}
					else
					{
						Adj_Matrix[i][j] = rand() % 10;
					}
				}
			}
		}

	}

	AdjacencyMatrix()
	{
		cout << "Enter Dimension: ";
		cin >> Dim;
		cout << "Enter Orientation: ";
		cin >> Orientation;
		Adj_Matrix = new int* [Dim];
		Creating();
	}

	~AdjacencyMatrix()
	{
		delete[] Adj_Matrix;
	}
};


