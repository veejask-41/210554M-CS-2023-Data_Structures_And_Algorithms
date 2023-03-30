#include <iostream>
using namespace std;

int add(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int a;
    int b;
    int total;

    cout << "Enter num 1 : ";
    cin >> a;
    cout << "Enter num 2 : ";
    cin >> b;

    total = add(a, b);
    cout << "Total is " << total;
    return 0;
}