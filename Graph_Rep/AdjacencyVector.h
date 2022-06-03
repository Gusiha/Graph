#pragma once
#define REPLACE = false

class AdjacencyVector
{
public:

	#pragma region Data

	int Dim;
	bool Orientation;
	int Degree;
	int** Adj_Vector;

	#pragma endregion

	void Print()
	{
		cout << "\n\t[AdjacencyVector]" << endl;
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				cout << setw(2) << Adj_Vector[i][j] << " ";
			}
			cout << endl;
		}
	}
#ifdef REPLACE == true

	AdjacencyVector(AdjacencyMatrix& adjacencyMatrix)
	{
		// Data Transfer
		Dim = adjacencyMatrix.Dim;
		Orientation = adjacencyMatrix.Orientation;
		Degree = adjacencyMatrix.FindDegree();

		// Filling Array
		Adj_Vector = new int* [Dim];

		for (int i = 0; i < Dim; i++)
		{
			Adj_Vector[i] = new int[Degree];
		}

		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				Adj_Vector[i][j] = 0;
			}
		}

		// Transition Algorithm (AdjMatrix -> AdjVector)
		int Column = 0;
		for (int i = 0; i < adjacencyMatrix.Dim; i++)
		{
			for (int j = 0; j < adjacencyMatrix.Dim; j++)
			{
				if (adjacencyMatrix.Adj_Matrix[i][j])
				{
					Adj_Vector[i][Column] = j + 1;
					Column++;
				}
			}

			Column = 0;
		}
	}

#else
	AdjacencyVector(AdjacencyMatrix adjacencyMatrix)
	{
		// Data Transfer
		Dim = adjacencyMatrix.Dim;
		Orientation = adjacencyMatrix.Orientation;
		Degree = adjacencyMatrix.FindDegree();

		// Filling Array
		Adj_Vector = new int* [Dim];

		for (int i = 0; i < Dim; i++)
		{
			Adj_Vector[i] = new int[Degree];
		}

		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				Adj_Vector[i][j] = 0;
			}
		}

		// Transition Algorithm (AdjMatrix -> AdjVector)
		int Column = 0;
		for (int i = 0; i < adjacencyMatrix.Dim; i++)
		{
			for (int j = 0; j < adjacencyMatrix.Dim; j++)
			{
				if (adjacencyMatrix.Adj_Matrix[i][j])
				{
					Adj_Vector[i][Column] = j + 1;
					Column++;
				}
			}

			Column = 0;
		}
	}
#endif // REPLACE


};