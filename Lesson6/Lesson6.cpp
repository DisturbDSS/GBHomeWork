
#include <iostream>
#include <fstream>
#include <string>


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

void buildRandArray(int** ptrArr, size_t sizeM, size_t sizeN) //task2func
{
	for (size_t i = 0; i < sizeM; i++)
	{
		for (size_t j = 0; j < sizeN; j++)
		{
			ptrArr[i][j] = rand() % 99;
		}
	}

}

void printMatrix(int** ptrArr, size_t sizeN, size_t sizeM) //task2func
{
	for (size_t i = 0; i < sizeN; ++i)
	{
		for (size_t j = 0; j < sizeM; ++j)
		{
			cout << ptrArr[i][j] << ' ';
		}
		cout << endl;
	}
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

void CopyFile(ifstream& finX, ofstream& foutX)
{
	string str;
	while (!finX.eof())
	{
		getline(finX, str);
		foutX << str << endl;
	}

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

		printMatrix(ptrArr, m, n);

		deleteArray(ptrArr, m);


	}

	//task3
	{
		string fname1, fname2;
		cout << "How to name a new file .txt: ";
		cin >> fname1;
		cout << "How to name a new file .txt: ";
		cin >> fname2;

		const size_t size = 75;
		int arrayToFile[size];
		ofstream fout1(fname1, ios_base::app);
		ofstream fout2(fname2, ios_base::app);
		for (size_t i = 0; i < size; ++i)
		{
			arrayToFile[i] = rand() % 75;
			fout1 << "elem[" << i << "] = " << arrayToFile[i] << endl;
			fout2 << "elem[" << i << "] = " << arrayToFile[i] * (rand() % 10) << endl;
		}
		fout1.close();
		fout2.close();

		//task4
		{
			string fname1, fname2, fname12;
			cout << "Enter file name 1 for reading: ";
			cin >> fname1;
			cout << "Enter file name 2 for reading: ";
			cin >> fname2;
			cout << "Enter new mergre file name: ";
			cin >> fname12;

			ifstream fin1(fname1);
			ifstream fin2(fname2);
			ofstream fout12(fname12);

			if (fin1.is_open() && fin2.is_open() && fout12.is_open())
			{
				CopyFile(fin1, fout12);
				fin1.close();

				CopyFile(fin2, fout12);
				fin1.close();

				fout12.close();
			}
		}
	}

	return 0;
}

