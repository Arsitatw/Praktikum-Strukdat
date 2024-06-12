#include <iostream>
using namespace std;

int factorialHelper(int n, int accumulator);

int factorial(int n) {
    return factorialHelper(n, 1);
}

int factorialHelper(int n, int accumulator) {
    if (n == 0 || n == 1) {
        return accumulator;
    } else {
        return factorial(n - 1) * n;
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
