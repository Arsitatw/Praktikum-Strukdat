#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;
    cout << "masukkan bilangan bulat positif: ";
    cin >> number;
    if (number < 0) {
        cout << "masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "faktorial dari bilangan " << number << " adalah " << result << endl;
    }

    return 0;
}
