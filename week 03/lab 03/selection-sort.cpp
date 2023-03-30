#include <iostream>
#include <random>
#include <chrono>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // swap the elements
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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
        selectionSort(arr, size);
        auto end_time = chrono::steady_clock::now();
        auto time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        // printing the final sorted array
        cout << "Sorted array after insertion sort : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        cout << "Time taken : " << time_taken << " microseconds" << endl;
    }
}
