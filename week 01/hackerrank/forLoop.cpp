#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    
    string num[9] = {"one","two","three","four","five","six","seven","eight","nine"};

    for (int i=a; i<=b; i++){
        if (i <= 9) {
            cout << num[i-1] << endl;
        } else {
            if (i%2 == 1) {
                cout << "odd" << endl;
            } else {
                cout << "even" << endl;
            }
        }
    }

    return 0;
}