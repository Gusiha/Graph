#define REPLACE
//#define DEBUG
#include <iostream>
#include <ctime>
#include <iomanip>
#include <list>
#include "AdjacencyMatrix.h"
#include "AdjacencyVector.h"
#include "AdjacencyListClass.h"


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	
	AdjacencyMatrix Graph;
	Graph.Print();
		
	AdjacencyVector Graph2(Graph);
	Graph2.Print();

	AdjacencyListClass Graph3(Graph2);
	Graph3.Print();
	
}



