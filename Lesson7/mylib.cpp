
#include <iostream>

using namespace std;

namespace taskLib

#define SWAPINT(i,j)\
	temp = array[j - 1];\
	array[j - 1] = array[j];\
	array[j] = temp;

{
	float* initArrayf(const size_t size)
	{
		float* ptr = 0;
		ptr = new float[size];
		return ptr;
	}

	float* myArrayf(float array[], size_t size)
	{
		cout << "Size of array is: " << size << endl;
		int positivX = 0, negativX = 0;

		for (int i = 0; i < size; i++)
		{
			cout << "Enter " << i+1 << " variable: ";
			cin >> array[i];
			if (array[i] >= 0)
				positivX++;
			else
				negativX++;
		}
		cout << endl << "Positiv variables: " << positivX << "  Negativ variables: " << negativX << endl;
		return array;
	}

	float* inputArray(float array[], size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Enter " << i + 1 << " variable: ";
			cin >> array[i]; 
		}
		return array;
	}
	
	void printArrayf(float array[], size_t size)
	{
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << " your array is printed!" << endl;
	}

	int* bubbleSort(int array[], size_t size)
	{
		int temp, i, j;
		for (int i = 0; i < size; i++)
		{
			for (j = size - 1; j > i; j--)
			{
				if (array[j - 1] > array[j]) //go to swap if last number is smaller than previous one
				{
					SWAPINT(i, j);
				}
			}
		}
		return array;
	}
}