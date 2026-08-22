// Program to Calculate a^n mod m Using Recursion
#include <iostream>
using namespace std;

long long powerMod(int a, int n, int m) {

    if (n == 0)
        return 1 % m;

    return (a * powerMod(a, n - 1, m)) % m;
}

int main() {
    int a, n, m;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;

    cout << a << "^" << n << " mod " << m
         << " = " << powerMod(a, n, m) << endl;

    return 0;
}