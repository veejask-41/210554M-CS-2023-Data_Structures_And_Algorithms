#include <iostream>
using namespace std;

int factorial_recursive(int n)
{
    try
    {
        if (n < 0)
        {
            throw "Factorial of negative number is not defined";
        }
        else if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial_recursive(n - 1);
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
}

int main()
{
    int n = 5;
    cout << "Factorial of " << n << " is " << factorial_recursive(n) << endl;
    return 0;
}