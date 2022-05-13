#include "AdjacencyMatrix.h"
#include "AdjacencyVector.h"


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	
	AdjacencyMatrix* Example = new AdjacencyMatrix();

	Example->Print();
	cout << endl;
	Example->Degree = Example->FindDegree();

	AdjancencyVector* Graph = new AdjancencyVector(*Example);
	delete Example;
	// Graph.~AdjacencyMatrix();
	Graph->Print();
	cout << endl;

	AdjancencyVector Graph2;
	Graph2.Print();

	
	
}



