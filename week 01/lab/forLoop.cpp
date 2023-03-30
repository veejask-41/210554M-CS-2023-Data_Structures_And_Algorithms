#include <iostream>
using namespace std;

int main() {
    for (int i=0; i<10; i++){
        cout << i << endl;
    }

    // to iterate through an array
    int myNums[5] = {10,20,30,40,50};
    for (int i: myNums) {
        cout << i << endl;
    }

    return 0;
}