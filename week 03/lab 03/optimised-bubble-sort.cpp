#include <iostream>
#include <random>
#include <chrono>
using namespace std;

void optimisedBubbleSort(int arr[], int size)
{
    bool swapped; // flag to check if any swaps were made in the previous iteration
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // if no swaps were made in this iteration, the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    // initializing sizes for random arrays
    int sizes[5] = {1000, 5000, 10000, 15000, 20000};

    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000); // create random number between 1,1000

    for (int i = 0; i < 5; i++)
    {
        int size = sizes[i];
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = dis(gen); // assigning random number to array
        }

        // printing initial array
        cout << "Initial array with size " << size << " is : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        // calculating the time taken for sorting in microseconds
        auto start_time = chrono::steady_clock::now();
        optimisedBubbleSort(arr, size);
        auto end_time = chrono::steady_clock::now();
        auto time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        // printing the final sorted array
        cout << "Sorted array after bubble sort : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Time taken : " << time_taken << " microseconds" << endl;
    }
}
