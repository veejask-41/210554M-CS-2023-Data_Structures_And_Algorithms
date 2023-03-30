#include <iostream>
#include <random>
#include <chrono>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_iterative(int arr[], int size)
{
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size)
    {
        for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size)
        {
            int mid = min(left_start + curr_size - 1, size - 1);
            int right_end = min(left_start + 2 * curr_size - 1, size - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    // initializing sizes for random arrays
    int sizes[10] = {2500, 5000, 10000, 15000, 20000, 25000};    

    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000); // create random number between 1,1000

    for (int i = 0; i < 6; i++)
    {
        int size = sizes[i];
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = dis(gen); // assigning random number to array
        }

        // printing initial array
        // cout << "Initial array with size " << size << " is : ";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        // calculating the time taken for sorting in microseconds
        auto start_time = chrono::steady_clock::now();
        merge_sort_iterative(arr, size);
        auto end_time = chrono::steady_clock::now();
        auto time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        // printing the final sorted array
        // cout << "Sorted array after insertion sort : ";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        cout << "Time taken : "  << time_taken << " microseconds" << endl;
    }
}
