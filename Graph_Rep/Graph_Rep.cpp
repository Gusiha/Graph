#include "Header.h"



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int Dim;
	bool Type;
	// true - non-oriented
	// false - oriented

	cout << "Enter Dimension: ";
	cin >> Dim;
	cout << "Enter Type: ";
	cin >> Type;


	int** Adj_Matrix = new int* [Dim];

	InitialCreating(Adj_Matrix, Dim, Type);

	


}



