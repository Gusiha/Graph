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


	void Print()
	{
		cout << "\n\t[IncidenceMatrix]" << endl;
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < EdgeAmount; j++)
			{
				cout << setw(2) << Incid_Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void FillIncidenceMatrix(const AdjacencyListClass& AdjacencyList)
	{
		int j = 0;
		
		cout << *AdjacencyList.Adj_List[0].begin();

		if (Orientation)
		{
			for (int i = 0; i < Dim; i++)
			{
				if (AdjacencyList.Adj_List[i].size() > 1)
				{

					if (*AdjacencyList.Adj_List[i].begin())
					{

						Incid_Matrix[i][j] = 1;

						cout << Incid_Matrix[*AdjacencyList.Adj_List[i].begin() - 1][j];
						Incid_Matrix[*AdjacencyList.Adj_List[i].begin() - 1][j] = -1;
						j++;
						
					}

					for (auto it = AdjacencyList.Adj_List[i].begin(); it != --AdjacencyList.Adj_List[i].end();)
					{
						Incid_Matrix[*it-1][j] = 1;
						Incid_Matrix[*++it-1][j] = -1;
						j++;
					}
				}
			}
		}

		else
		{
			for (int i = 0; i < Dim; i++)
			{
				for (auto it = AdjacencyList.Adj_List[i].begin(); it != AdjacencyList.Adj_List[i].end();)
				{
					Incid_Matrix[*it][j] = 1;

					// Iterator changes in "if" condition
					if (++it != AdjacencyList.Adj_List[i].end())
					{
						Incid_Matrix[*it][j] = 1;
					}

					// Revert the first vertex
					else
					{
						Incid_Matrix[*(--it)][j] = 0;
					}

					j++;
				}
			}
		}
	}

	IncidenceMatrix(AdjacencyListClass& AdjacencyList)
	{
		// Data Transfer
		Dim = AdjacencyList.Dim;
		Orientation = AdjacencyList.Orientation;
		Degree = AdjacencyList.Degree;
		EdgeAmount = FindEdgeAmount(AdjacencyList);


		// Define Dimension of Incid_Matrix
		Incid_Matrix = new int* [Dim];

		for (int i = 0; i < Dim; i++)
		{
			Incid_Matrix[i] = new int[EdgeAmount];
		}

		// Initial Filling Incid_Matrix
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < EdgeAmount; j++)
			{
				Incid_Matrix[i][j] = 0;
			}
		}

		FillIncidenceMatrix(AdjacencyList);
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


