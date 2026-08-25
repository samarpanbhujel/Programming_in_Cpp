/*
 * Assignment 4 - Question 1
 * Programs to compute a^n, b^n mod m, and linear search, etc.
 * all implemented using recursion.
 */
#include <iostream>
using namespace std;

// Recursively compute a^n
long long power(long long a, int n) {
    if (n == 0) return 1;
    return a * power(a, n - 1);
}

// Recursively compute (b^n) mod m using fast exponentiation
long long powerMod(long long b, int n, long long m) {
    if (n == 0) return 1 % m;
    if (n % 2 == 0) {
        long long half = powerMod(b, n / 2, m);
        return (half * half) % m;
    } else {
        return (b % m * powerMod(b, n - 1, m)) % m;
    }
}

// Recursive linear search; returns index of key in arr[0..n-1], or -1
int linearSearch(int arr[], int n, int key, int index = 0) {
    if (index >= n) return -1;
    if (arr[index] == key) return index;
    return linearSearch(arr, n, key, index + 1);
}

// Recursive factorial (bonus "etc" example commonly paired with these)
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int choice;
    do {
        cout << "\n--- Recursion Menu ---\n";
        cout << "1. Compute a^n\n";
        cout << "2. Compute b^n mod m\n";
        cout << "3. Linear Search\n";
        cout << "4. Factorial\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                long long a; int n;
                cout << "Enter base a and exponent n: ";
                cin >> a >> n;
                cout << a << "^" << n << " = " << power(a, n) << endl;
                break;
            }
            case 2: {
                long long b, m; int n;
                cout << "Enter base b, exponent n, and modulus m: ";
                cin >> b >> n >> m;
                cout << b << "^" << n << " mod " << m << " = "
                     << powerMod(b, n, m) << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int *arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                int idx = linearSearch(arr, n, key);
                if (idx == -1) cout << "Element not found.\n";
                else cout << "Element found at index " << idx << ".\n";
                delete[] arr;
                break;
            }
            case 4: {
                int n;
                cout << "Enter n: ";
                cin >> n;
                cout << n << "! = " << factorial(n) << endl;
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
