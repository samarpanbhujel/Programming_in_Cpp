// Program to Calculate a^n Using Recursion
#include <iostream>
using namespace std;

long long power(int a, int n) {
    if (n == 0)
        return 1;

    return a * power(a, n - 1);
}

int main() {
    int a, n;

    cout << "Enter base (a): ";
    cin >> a;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << a << "^" << n << " = "
         << power(a, n) << endl;

    return 0;
}