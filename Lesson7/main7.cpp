
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
	char FullName[32];
	char ID[16];
	char Phone[16];
};
#pragma pack(pop)

void outputf1(ofstream& f, char a[32], char b[16], char c[16], string fname)//write function

{
	f.open(fname);//open file
		  //Check if opened successfully
	if (f.fail()) {
		cout << "\n File can't be opened";
		exit(1);
	}
	f << "Name: " << a << endl;//write to the file
	f << "ID: " << b << endl;
	f << "Phone: " << c << endl;
	f.close();
}

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

		int const elmnt = 1;
		Employee content[elmnt];

		for (int i = 0; i < elmnt; ++i)
		{
			cout << "Enter full name: " << endl;
			cin >> content[i].FullName;
			cout << "Enter ID: " << endl;
			cin >> content[i].ID;
			cout << "Enter phone number: " << endl;
			cin >> content[i].Phone;
		}

		ofstream f1;

		string fname = "employee.txt";
		for (int i = 0; i < elmnt; ++i)
		{
			outputf1(f1, content[i].FullName, content[i].ID, content[i].Phone, fname);
		}

		delete strc;
	}

	return 0;
}
