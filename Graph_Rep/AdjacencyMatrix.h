#pragma once
#include <iostream>
#include <ctime>

using namespace std;
struct AdjacencyMatrix;
struct AdjancencyVector;

struct AdjacencyMatrix
{
	#pragma region 
	int Dim;
	bool Orientation;
	int** Adj_Matrix;
	int Degree;
	#pragma endregion

	int FindDegree()
	{
		int MaxCount = 0;

		if (Orientation)
		{
			int count = 0;
			for (int i = 0; i < Dim; i++)
			{
				for (int j = 0; j < Dim; j++)
				{
					if (Adj_Matrix[i][j])
					{
						count++;
					}
				}
				if (count >= MaxCount)
				{
					MaxCount = count;
				}
				count = 0;
			}
			Degree = MaxCount;
		
		}

		else
		{
			int count = 0;
			for (int i = 0; i < Dim; i++)
			{
				for (int j = 0; j < Dim; j++)
				{
					if (Adj_Matrix[i][j])
					{
						count++;
					}
				}
				if (count >= MaxCount)
				{
					MaxCount = count;
				}
				count = 0;
			}
			
			Degree = MaxCount;
			
		}
		return Degree;
	}

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

		if (!Orientation)
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

	~AdjacencyMatrix();
	// {
	// 	cout << "\n*AdjacencyMatrix*" << endl;
	// };
	
};


