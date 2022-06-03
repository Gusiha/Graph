#include "AdjacencyMatrix.h"
#include "AdjacencyVector.h"


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	
	AdjacencyMatrix Graph;
	Graph.Print();
	
	
	AdjacencyVector Graph1(Graph);
	Graph.Print();
	Graph1.Print();

	
	//Graph.Degree = Graph.FindDegree();

	//AdjacencyVector Graph1(Graph);

	//Graph1.Print();
	

	
}



