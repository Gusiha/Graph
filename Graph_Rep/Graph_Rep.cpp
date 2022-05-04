#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int Dim;

	cout << "Enter Dimension: ";
	cin >> Dim;

	int** Adj_Matrix = new int* [Dim];


	for (int i = 0; i < Dim; i++)
	{
		Adj_Matrix[i] = new int[Dim];
	}

	for (int i = 0; i < Dim; i++) // ввод 
	{
		for (int j = 0; j < Dim; j++)
		{
			Adj_Matrix[i][j] = rand() % 1;
		}
	}

	for (int i = 0; i < Dim; i++) // ввод 
	{
		for (int j = 0; j < Dim; j++)
		{
			cout << Adj_Matrix[i][j] << " ";
		}
		cout << endl;
	}

}


