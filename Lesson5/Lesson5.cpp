
#include <iostream>
using namespace std;


void printArr(double arr[], const size_t size) ////task1function
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Array is printed" << endl;
    
}

void printOut(int* arr, const int size) ////task2function
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Replacer(int* arr, const int size) ////task2function
{
    for (int i = 0; i < size; i++)
        if (arr[i]) arr[i] = 0;
        else arr[i] = 1;

}

void initArr(int* arr, int size) ////task3function
{
    int arr0[8] = { 1, 4, 7, 10, 13, 16, 19, 22 };
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr0[i];
    }
}

void shift(int* arr, int size, int nShift) ////task4function
{
    int index;
    int arr0[8];
    for (int i = 0; i < size; i++)    
    {
        index = i + nShift - size;
        
        if ((i + nShift) >= size)
            index = i + nShift - size;
        else index = i + nShift;
        arr0[index] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = arr0[i];
    }
}


bool checkBalance(int* arr, int size) ////task5function
{
    int leftside, rightside;
    for (int i = 0; i < size; i++)
    {
        leftside = 0;
        rightside = 0;

        int arrleft;
        for (arrleft = 0; arrleft < i; arrleft++)
        {
            leftside += arr[arrleft];
        }

        int arrright;
        for (arrright = arrleft; arrright < size; arrright++)
        {
            rightside += arr[arrright];
        }

        if (leftside == rightside)

        {
            cout << "True, balanced" << endl;
            return true;
        }

        
        
    }
    cout << "False, NOT balanced" << endl;

}


int main()
{
    {   //task1
        const int arrsize = 5;
        double arr1[] = { 3.2, 5, 6, 8, 10 };
        printArr(arr1, arrsize);
    }

    {
        //task2
        const int arrsize = 9;
        int arr2[] = { 1, 0, 0, 1, 0, 1, 1, 0, 0 };

        printOut(arr2, arrsize);
        Replacer(arr2, arrsize);
        printOut(arr2, arrsize);
    }


    {
        //task3
        const int arrsize = 8;
        int arr3[arrsize];
        initArr(arr3, arrsize);
        printOut(arr3, arrsize);

    }


    {
        //task4
        int nShift;
        cout << " Enter number offset 0-8: ";
        cin >> nShift;
        const int arrsize = 8;
        int origin[arrsize] = { 1, 4, 7, 10, 13, 16, 19, 22 };

        if (nShift <= arrsize)
        {
            shift(origin, arrsize, nShift);
            printOut(origin, arrsize);
        }

        else
            cout << "Number is out of range!";

    }


    {
        //task5
        const int arrsize = 6;
        int arr5[arrsize] = { 1, 2, 3, 3, 2, 1 };

        printOut(arr5, arrsize);
        checkBalance(arr5, arrsize);

    }

    return 0;
}