
#include <iostream>
#include <fstream>
#include "mylib.h"

using namespace std;
using namespace taskLib;

//Macros//
#define CHECK_NUM_RANGE(numCheck, range) (numCheck >= 0 && numCheck < range)
#define ARR_SIZE 7
//

#pragma pack(push, 1)
struct Employee
{
	char FullName[255];
	char Address[255];
	short int ID;
	long long Phone;
};
#pragma pack(pop)

int main()
{
	
	//task1
	{
		size_t size;
		cout << "Enter size of array: ";
		cin >> size;
		float* ptr = 0;
		

		ptr = taskLib::initArrayf(size);
		taskLib::myArrayf(ptr, size);
		taskLib::printArrayf(ptr, size);

		delete[]ptr;
	}

	//task2
	{
		int number;
		bool res;
		const int range = 100;

		cout << endl << "Your range is 99. Enter your number: ";
		cin >> number;
		res = CHECK_NUM_RANGE(number, range);
		cout << " Number in range: " << boolalpha << res << endl;
	
	}


	//task3
	{
		float* ptr = 0;

		float arr[ARR_SIZE];

		ptr = taskLib::initArrayf(ARR_SIZE);
		taskLib::inputArray(arr, ARR_SIZE);

		int arr3[ARR_SIZE];

		for (int i = 0; i < ARR_SIZE; i++) //floar <-> int SwapArray
		{
			arr3[i] = arr[i];
		}

		taskLib::bubbleSort(arr3, ARR_SIZE);

		for (int i = 0; i < ARR_SIZE; i++) //int <-> float SwapArray
		{
			arr[i] = arr3[i];
		}

		taskLib::printArrayf(arr, ARR_SIZE);

	}

	//task4
	{
		auto strc = new Employee;
		cout << "Your file size: " << sizeof(Employee) << " bytes" << endl;

		string fname = "employee.txt";
		ofstream fout(fname, ios_base::app);
		fout.open(fname);

		if (fout.is_open())
		{
			fout.write ((char*)strc, sizeof(strc));	
		}
		else 
		{
			cout << "Error..." << endl;
		}
		
		fout.close();
		delete strc;

	}

	return 0;
}
