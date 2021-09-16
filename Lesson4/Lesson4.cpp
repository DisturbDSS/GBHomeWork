
#include <iostream>

using namespace std;

int main()

{
	//task1
	{
		int a, b;
		cout << " Enter first value(task1): " ;
		cin >> a;
		cout << " Enter second value: " ;
		cin >> b;
		if (a + b >= 10 && a + b <= 20)
		{
			cout << "True" << endl;
		}
		else
		{
			cout << " False" << endl;
		}
	}

	//task2
	{
		const int c = 1;
		const int d = 5;

		cout << " task2 " << endl;
		if (c + d == 10 || (c == 10 && d == 10))
		{
			cout << " True " << endl;
		}
		else
		{
			cout << " False " << endl;
		}

	}

	//task3(for)
	{
		cout << " Your numbers(for)(task3): ";
		for (int i = 1; i <= 50; ++++i)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	//task3(while)
	{
		int i = 1;
		cout << " Your numbers(while)(task3): ";

		while (i < 50)

		{
			if (i % 2 != 0)
				cout << i << " ";
			i++;
		}
		cout << endl;

	}

	//task4
	{
		int b;
		bool c = false;
		cout << " Enter number >1 to check(task4): ";
		cin >> b;
		if (b > 1) 
		{

			for (int i = 2; i < (b); i++)
			{
				if (b % i == 0)
				{
					c = true;
					break;
				}
			}
			if (c == true)
			{
				cout << " Number is NOT prime " << endl;
			}
			else
			{
				cout << " Number is prime " << endl;
			}
		}
		else
			cout << " Number should be >1 " << endl;

	}

	//task5
	{
		int year;
		cout << "Enter year up to 3000: ";
		cin >> year;

		if (year > 0 && year <= 3000)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				cout << "It's a leap year" << endl;
			}
			else
			{
				cout << "It's NOT a leap year" << endl;
			}
		}
		else 
			cout << "Year is out of range" << endl;
	}

	return 0;
}