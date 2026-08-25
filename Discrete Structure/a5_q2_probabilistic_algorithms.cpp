/*
 * Assignment 5 - Question 2
 * Program to implement probabilistic/randomized algorithms:
 * 1. Randomized QuickSort (Las Vegas algorithm - always correct,
 *    random running time)
 * 2. Monte Carlo Primality Test using Fermat's Little Theorem
 *    (may occasionally be wrong, but is fast)
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Randomized QuickSort ----------
int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int p = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, p - 1);
        randomizedQuickSort(arr, p + 1, high);
    }
}

// ---------- Monte Carlo Primality Test (Fermat test) ----------
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool fermatPrimalityTest(long long n, int iterations) {
    if (n < 4) return n == 2 || n == 3;
    for (int i = 0; i < iterations; i++) {
        long long a = 2 + rand() % (n - 3); // random a in [2, n-2]
        if (modPow(a, n - 1, n) != 1) return false; // definitely composite
    }
    return true; // probably prime
}

int main() {
    srand((unsigned)time(0));
    int choice;
    do {
        cout << "\n--- Probabilistic / Randomized Algorithms Menu ---\n";
        cout << "1. Randomized QuickSort\n";
        cout << "2. Monte Carlo Primality Test (Fermat test)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                vector<int> arr(n);
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                randomizedQuickSort(arr, 0, n - 1);
                cout << "Sorted array: ";
                for (int x : arr) cout << x << " ";
                cout << endl;
                break;
            }
            case 2: {
                long long n;
                int iterations;
                cout << "Enter number to test for primality: ";
                cin >> n;
                cout << "Enter number of test iterations (e.g. 10): ";
                cin >> iterations;
                bool result = fermatPrimalityTest(n, iterations);
                cout << n << " is " << (result ? "probably PRIME" : "COMPOSITE")
                     << " (based on " << iterations << " random trials)\n";
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
