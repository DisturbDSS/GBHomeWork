
#include <iostream>

using namespace std;

void buildArray(int* ptrArr, int n) //task1func
{
	int varArr = 1;
	for (size_t i = 0; i < n; i++)
	{
		ptrArr[i] = varArr;
		cout << ptrArr[i] << " ";
		varArr *= 2;
	}
	cout << endl << "Printed " << n << " values..." << endl;
}

int** allocMemory(size_t m, size_t n) //task2func
{
	int** ptrArr = new (nothrow) int* [m];
	for (size_t i = 0; i < m; i++)
	{
		ptrArr[i] = new (nothrow) int[n]; //arrays n in m
	}
	return ptrArr;
}

int** buildRandArray(size_t sizeM, size_t sizeN) //task2func
{
	for (size_t i = 0; i < sizeM; i++)
	{
		for (size_t j = 0; j < sizeN; j++)
		{
			ptrArr[i][j] = rand() % 99;
		}
	}
	return ptrArr;
}

void deleteArray(int** ptrArr, size_t m) //task2func
{
	for (size_t i = 0; i < m; i++)
	{
		delete[] ptrArr[i];
	}
	delete[] ptrArr;
	ptrArr = nullptr;
}

int main()
{

	//task1
	{
		int* ptrArr;
		int n;
		cout << "Enter size of array: ";
		cin >> n;
		if (n > 0)
		{
			ptrArr = new (nothrow) int[n];
			if (ptrArr != nullptr)
			{
				cout << "Array: ";
				buildArray(ptrArr, n); //function for array
				delete[] ptrArr; // clean memory
				ptrArr = nullptr;		
			}
		}
		else
			cout << "Memory can not be allocated!" << endl;
	}

	//task2
	{
		size_t m, n; //matrix m x n
		cout << "Enter m: ";
		cin >> m;
		cout << "Enter n: ";
		cin >> n;

		//memory allocation
		int** ptrArr = allocMemory(m, n);

		cout << endl;
		buildRandArray(ptrArr, m, n);
		

		deleteArray(ptrArr, m);

		return 0;
		
	}










}

