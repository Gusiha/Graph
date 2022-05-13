#include "AdjacencyMatrix.h"
#include "AdjacencyVector.h"


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	
	AdjacencyMatrix Graph;

	Graph.Print();
	cout << endl;
	Graph.Degree = Graph.FindDegree();

	AdjancencyVector Graph1(Graph);

	Graph1.Print();
	

	
}



