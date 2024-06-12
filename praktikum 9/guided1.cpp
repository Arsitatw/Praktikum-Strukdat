#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return; 
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    int number = 5; 

    cout << "Rekursif Langsung: ";
    countdown(number);
    cout << endl;

    return 0;
}