#pragma once

using namespace std;
class AdjacencyMatrix;
class AdjacencyVector;
class AdjacencyListClass;

class AdjacencyMatrix
{
public:

	#pragma region Data
	int Dim;
	bool Orientation;
	int** Adj_Matrix;
	#pragma endregion

	int FindDegree()
	{
		int Degree = 0;
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
		cout << "\n\t[AdjacencyMatrix]" << endl;
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Dim; j++)
			{
				cout << setw(2) << Adj_Matrix[i][j] << " ";
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
						Adj_Matrix[i][j] = rand() % 20;
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
						Adj_Matrix[i][j] = rand() % 20;
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

	AdjacencyMatrix(const AdjacencyMatrix& Old)
	{
		cout << "*Start Copy Constructor*" << endl;
		Dim = Old.Dim;
		Orientation = Old.Orientation;
		Adj_Matrix = new int* [Dim];
		for (int i = 0; i < Dim; i++)
		{
			Adj_Matrix[i] = new int[Dim];
		}

		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Dim; j++)
			{
				Adj_Matrix[i][j] = Old.Adj_Matrix[i][j];
			}
		}
		
		cout << "*Finish Copy Constructor*" << endl;

	}

	~AdjacencyMatrix()
	{
		for (int i = 0; i < Dim; i++)
		{
			delete[] Adj_Matrix[i];
		}
		delete[] Adj_Matrix;
		#ifdef DEBUG
		cout << "*Destructor AdjacencyMatrix*" << endl;;
		#endif // DEBUG

		
	}

};


