#include <iostream>
using namespace std;

int main() {
    char gender;
    cout << "Enter gender (f/m) : ";
    cin >> gender;
    if (gender == 'f') {
        cout << "You are female";
    } else if (gender == 'm') {
        cout << "You are male";
    } else {
        cout << "You are GAY!!!";
    }
    return 0;
}