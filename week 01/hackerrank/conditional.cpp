#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter num : ";
    cin >> n;
    
    string num[9] = {"one","two","three","four","five","six","seven","eight","nine"};

    if (n <= 9) {
        cout << num[n-1];
    } else {
        cout << "Greater than 9";
    }

    return 0;
}