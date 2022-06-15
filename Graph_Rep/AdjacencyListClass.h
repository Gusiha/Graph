#pragma once

class AdjacencyListClass
{

public:
	int Dim;
	bool Orientation;
	int Degree;
	list<int>* Adj_List;

	AdjacencyListClass(AdjacencyVector& adjacencyVector)
	{
		// Data Transfer
		Dim = adjacencyVector.Dim;
		Orientation = adjacencyVector.Orientation;
		Degree = adjacencyVector.Degree;

		// Define Dimension of Array List
		Adj_List = new list<int>[Dim];

		// Filling Array
		for (int i = 0; i < Dim; i++)
		{
			for (int j = 0; j < Degree; j++)
			{
				if (adjacencyVector.Adj_Vector[i][j] == 0)
					break;

				Adj_List[i].push_back(adjacencyVector.Adj_Vector[i][j]);
			}
		}
	}

	void Print()
	{
		cout << "\n\t[AdjacencyList]\n";
		for (int i = 0; i < Dim; i++)
		{
			cout << "[" << i+1 << "] => ";

			for (auto it = Adj_List[i].begin(); it != Adj_List[i].end(); ++it)
			{
				if (*it == Adj_List[i].back())
					cout << *it;
				else
					cout << *it << "->";				
			}
			cout << endl;
		}
	}

	~AdjacencyListClass()
	{
		delete[] Adj_List;
		#ifdef DEBUG
		cout << "*Destructor Adj_List *" << endl;
		#endif // DEBUG

	}
};

