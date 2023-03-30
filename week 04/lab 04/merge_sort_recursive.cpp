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

void merge_sort_recursive(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort_recursive(arr, l, m);
        merge_sort_recursive(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    // initializing sizes for random arrays
    int sizes[7] = {2500, 5000, 10000, 15000, 20000, 25000, 30000};

    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000); // create random number between 1,1000

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
        merge_sort_recursive(arr, 0, size - 1);
        auto end_time = chrono::steady_clock::now();
        auto time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        // printing the final sorted array
        // cout << "Sorted array after insertion sort : ";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        cout << "Time taken : " << time_taken << " nanoseconds" << endl;
    }
}
