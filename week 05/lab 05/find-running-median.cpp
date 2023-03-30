#include <iostream>
#include <iomanip>
using namespace std;

void findRunningMedian(int arr[], int size)
{
    double median;
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        if (i % 2 == 0)
        {
            median = arr[i / 2];
        }
        else
        {
            median = (arr[i / 2] + arr[(i / 2) + 1]) / 2.0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << fixed;
    cout << setprecision(1);
    cout << setw(10 - 2 * size + 3) << median << endl;
}

int main()
{
    int size = 4;
    int arr[size] = {7,
                     3,
                     5,
                     2};

    cout << "sorted"
         << "    "
         << "median" << endl;
    for (int i = 0; i < size; i++)
    {
        findRunningMedian(arr, i + 1);
    }
}