#include <iostream>
#include <chrono>
#include <random>
using namespace std;

void quickSortIterative(int arr[], int start, int end)
{
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0)
    {
        end = stack[top--];
        start = stack[top--];

        int i = start, j = end;
        int tmp;
        int pivot = arr[(start + end) / 2];

        /* partition */
        while (i <= j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        };

        /* push values to stack */
        if (i < end)
        {
            stack[++top] = i;
            stack[++top] = end;
        }
        if (start < j)
        {
            stack[++top] = start;
            stack[++top] = j;
        }
    }
}


int main()
{
    // initializing sizes for random arrays
    int sizes[1] = {25000};

    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000); // create random number between 1,1000

    for (int i = 0; i < 1; i++)
    {
        int size = sizes[i];
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = dis(gen); // assigning random number to array
        }

        // calculating the time taken for sorting in microseconds
        auto start_time = chrono::steady_clock::now();
        quickSortIterative(arr, 0, size - 1);
        auto end_time = chrono::steady_clock::now();
        auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

        cout << "Time taken : " << time_taken << " nanoseconds" << endl;
    }
    return 0;
}