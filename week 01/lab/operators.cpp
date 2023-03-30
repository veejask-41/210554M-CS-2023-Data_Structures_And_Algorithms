#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // arithmetic
    cout << (2 + 3 * 4) << endl;
    cout << (2 + 3) * 4 << endl;
    cout << pow(2, 10) << endl;   // 1024
    cout << float(6) / 3 << endl; // 2
    cout << float(7) / 3 << endl; // 2.33333
    cout << 7 / 3 << endl;        // In C++ this is integer division
    cout << 7 % 3 << endl;        // 1
    cout << float(3) / 6 << endl; // 0.5
    cout << 3 / 6 << endl;        // 0
    cout << 3 % 6 << endl;        // 3
    cout << pow(2, 100) << endl;

    // relational
    cout << (5 == 10) << endl;               // 0
    cout << (10 > 5) << endl;                // 1
    cout << ((5 >= 1) && (5 <= 10)) << endl; // 1

    // logical
    int x = 5;
    int y = 3;
    cout << (x > 3 && x < 10) << endl;    // returns true (1) because 5 is greater than 3 AND 5 is less than 10
    cout << (x > 3 || x < 4) << endl;     // returns true (1) because one of the conditions are true (5 is greater than 3, but 5 is not less than 4)
    cout << (!(x > 3 && x < 10)) << endl; // returns false (0) because ! (not) is used to reverse the result

    return 0;
}