#pragma once

struct AdjancencyVector
{
	int Dim;
	bool Orientation;
	int Degree;
	int** Adj_Vector;

	void Print()
	{
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				cout << Adj_Vector[i][j] << " ";
			}
			cout << endl;
		}
	}

	AdjancencyVector()
	{
		cout << "Enter Dimension: ";
		cin >> Dim;
		cout << "Enter Orientation: ";
		cin >> Orientation;
		cout << "Enter Degree: ";
		cin >> Degree;

		Adj_Vector = new int* [Dim];
		
		for (int i = 0; i < Dim; i++)
		{
			Adj_Vector[i] = new int[Degree];
		}

		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				Adj_Vector[i][j] = Dim - rand() % Dim;
			}
		}
		
	}

	AdjancencyVector(AdjacencyMatrix &adjacencyMatrix)
	{
		// Data Graph
		Dim = adjacencyMatrix.Dim;
		Orientation = adjacencyMatrix.Orientation;
		Degree = adjacencyMatrix.Degree;

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
				else
				{
					Adj_Vector[i][Column] = 0;
				}

			}

			Column = 0;
		}
		
	}

	// ~AdjancencyVector();
	
};