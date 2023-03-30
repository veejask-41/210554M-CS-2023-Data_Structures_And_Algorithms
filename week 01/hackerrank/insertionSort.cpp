#include <iostream>
using namespace std;

void insertionSort(int n, int *arr)
{
    for (int i = n - 1; i > 0; i--) // looping reversly through array indices
    {
        int value, hole;                              // initializing variables for our hole and key value
        value = arr[i];                               // storing the rightmost value in  key value
        hole = i;                                     // initializing rightmost array index as a hole
        while (hole > 0 && arr[hole] < arr[hole - 1]) // checking the condition is hole moved the left most place or left element is greater than right element
        {
            arr[hole] = arr[hole - 1]; // shifting elements
            hole = hole - 1;
            // printing out the intermediate state after each shift
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        arr[hole] = value; // finally storing our key value in the correct position in this iteration
    }
    
    //printing out the sorrted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int myArr[5] = {2, 4, 6, 8, 3};
    insertionSort(5, myArr);
    return 0;
}