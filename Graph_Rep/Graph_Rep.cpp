#include "Header.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	
	// true - �����������������
	// false - ���������������

	cout << "Enter Dimension: ";
	cin >> Dim;
	cout << "Enter Type: ";
	cin >> Type;
	


	int** Adj_Matrix = new int* [Dim];

	InitialCreating(Adj_Matrix);
	Max_Degree = FindDegree(Adj_Matrix);
	Print(Adj_Matrix);

	
	delete[] Adj_Matrix;
}



