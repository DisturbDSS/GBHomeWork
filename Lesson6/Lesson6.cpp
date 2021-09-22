
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

int** allocMemory(size_t n, size_t m)
{
	int** ptrArr = new (nothrow) int* [n];
	for (size_t i = 0; i < 0; i++)
	{
		ptrArr[i] = new (nothrow) int[m]; //arrays n in m
	}
	return ptrArr;
}

void buildRandArray(int* ptrArr, int sizeM, int sizeN) //task2func
{
	for (size_t i = 0; i < sizeM; i++)
	{
		for (size_t i = 0; i < sizeN; i++)
		{
			ptrArr[i] = rand() % 99;
			cout << ptrArr[i] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void deleteArray(int** ptrArr, size_t n) //task2func
{
	for (size_t i = 0; i < n; i++)
	{
		delete[] ptrArr[i];
	}
	delete[] ptrArr;
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
		int** ptrArr;
		const size_t m = 7, n = 4; //matrix 4x4
		//memory allocation
		ptrArr = new (nothrow) int* [m]; //array of pointers for n
		for (size_t i = 0; i < m; i++)
		{
			ptrArr[i] = new (nothrow) int[n]; //arrays n in m
		}
		cout << endl;
		buildRandArray(*ptrArr, m, n);

		
		
	}










}

