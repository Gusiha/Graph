#pragma once

class IncidenceMatrix
{
public:
	int Dim;
	bool Orientation;
	int Degree;
	int EdgeAmount;

	int** Incid_Matrix;

	int FindEdgeAmount(AdjacencyListClass& AdjacencyList)
	{
		int count = 0;
		for (int i = 0; i < Dim; i++)
		{
			for (auto it = AdjacencyList.Adj_List[i].begin(); it != AdjacencyList.Adj_List[i].end(); ++it)
			{
				count++;
			}
		}
		return count;
	}

	IncidenceMatrix(AdjacencyListClass& AdjacencyList)
	{
		// Data Transfer
		Dim = AdjacencyList.Dim;
		Orientation = AdjacencyList.Orientation;
		Degree = AdjacencyList.Degree;
		EdgeAmount = FindEdgeAmount(AdjacencyList);

		// Define Dimension of Incid_Array
		Incid_Matrix = new int* [Dim];

		for (int i = 0; i < Dim; i++)
		{
			Incid_Matrix[i] = new int[EdgeAmount];
		}
	}

	~IncidenceMatrix()
	{
		for (int i = 0; i < Dim; i++)
		{
			delete[] Incid_Matrix[i];
		}
		delete[] Incid_Matrix;
		cout << "*Incidence Destructor*" << endl;
	}

};


