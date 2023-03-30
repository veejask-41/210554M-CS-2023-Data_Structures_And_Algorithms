#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int karatsuba(int x, int y)
{
    // if x or y is less than 10, then return the product
    if (x < 10 || y < 10)
        return x * y;

    // find the maximum length of x and y
    int n = max(to_string(x).length(), to_string(y).length());

    // find the middle of the number
    int m = n / 2;

    // split the number into two parts
    int a = x / pow(10, m);
    int b = x % (int)pow(10, m);
    int c = y / pow(10, m);
    int d = y % (int)pow(10, m);

    // calculate the product of a and c
    int ac = karatsuba(a, c);

    // calculate the product of b and d
    int bd = karatsuba(b, d);

    // calculate the product of (a+b) and (c+d)
    int adbc = karatsuba(a + b, c + d) - ac - bd;

    // return the product
    return ac * pow(10, 2 * m) + (adbc * pow(10, m)) + bd;
}

int main()
{
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Product: " << karatsuba(x, y);
    return 0;
}
