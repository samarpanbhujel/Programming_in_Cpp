/*
    Assignment 4
    1. Programs to compute a^n, b^n mod m, linear search etc by using recursion
*/
#include <bits/stdc++.h>
using namespace std;

// a^n using recursion
long long power(long long a, long long n) {
    if (n == 0) return 1;
    long long half = power(a, n / 2);
    long long result = half * half;
    if (n % 2 == 1) result *= a;
    return result;
}

// b^n mod m using recursion (fast modular exponentiation)
long long powerMod(long long b, long long n, long long m) {
    if (n == 0) return 1 % m;
    long long half = powerMod(b, n / 2, m);
    long long result = (half * half) % m;
    if (n % 2 == 1) result = (result * (b % m)) % m;
    return result;
}

// Linear search using recursion
int linearSearchRec(const vector<int> &arr, int idx, int key) {
    if (idx >= (int)arr.size()) return -1;
    if (arr[idx] == key) return idx;
    return linearSearchRec(arr, idx + 1, key);
}

void computePower() {
    long long a, n;
    cout << "Enter base a and exponent n: ";
    cin >> a >> n;
    cout << a << "^" << n << " = " << power(a, n) << "\n";
}

void computePowerMod() {
    long long b, n, m;
    cout << "Enter base b, exponent n, and modulus m: ";
    cin >> b >> n >> m;
    cout << b << "^" << n << " mod " << m << " = " << powerMod(b, n, m) << "\n";
}

void linearSearch() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    int idx = linearSearchRec(arr, 0, key);
    if (idx == -1) cout << key << " not found in the array\n";
    else cout << key << " found at index " << idx << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 4 =====\n";
        cout << "1. Compute a^n (recursive)\n";
        cout << "2. Compute b^n mod m (recursive modular exponentiation)\n";
        cout << "3. Linear Search (recursive)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: computePower();    break;
            case 2: computePowerMod(); break;
            case 3: linearSearch();    break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
