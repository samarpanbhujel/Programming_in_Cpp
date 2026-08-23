/*
    Assignment 5
    1. Programs to generate permutations and combinations
    2. Programs to implement some probabilistic and randomized algorithms
*/
#include <bits/stdc++.h>
using namespace std;

// ---------- 1. Permutations and Combinations ----------
void generatePermutations(vector<int> &arr, int l) {
    if (l == (int)arr.size() - 1) {
        for (int x : arr) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = l; i < (int)arr.size(); i++) {
        swap(arr[l], arr[i]);
        generatePermutations(arr, l + 1);
        swap(arr[l], arr[i]);
    }
}

void generateCombinations(vector<int> &arr, int r, int start, vector<int> &current) {
    if ((int)current.size() == r) {
        for (int x : current) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i < (int)arr.size(); i++) {
        current.push_back(arr[i]);
        generateCombinations(arr, r, i + 1, current);
        current.pop_back();
    }
}

long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

void permutationsAndCombinations() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    cout << "1. Generate all Permutations\n2. Generate all Combinations of size r\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "All permutations:\n";
            generatePermutations(arr, 0);
            break;
        case 2: {
            int r;
            cout << "Enter r: ";
            cin >> r;
            cout << "All combinations of size " << r << " (nCr = " << nCr(n, r) << "):\n";
            vector<int> current;
            generateCombinations(arr, r, 0, current);
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

// ---------- 2. Probabilistic / Randomized algorithms ----------

// Randomized QuickSort: picks a random pivot
int randomPartition(vector<int> &arr, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[randIdx], arr[high]);
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
        int p = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, p - 1);
        randomizedQuickSort(arr, p + 1, high);
    }
}

// Monte Carlo primality test (Fermat's little theorem based)
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return result;
}

bool fermatMonteCarloTest(long long n, int iterations) {
    if (n < 4) return n == 2 || n == 3;
    for (int i = 0; i < iterations; i++) {
        long long a = 2 + rand() % (n - 3); // random a in [2, n-2]
        if (modPow(a, n - 1, n) != 1) return false; // definitely composite
    }
    return true; // probably prime
}

void randomizedAlgorithms() {
    int choice;
    cout << "1. Randomized QuickSort\n2. Monte Carlo Primality Test (Fermat)\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            vector<int> arr(n);
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];

            srand((unsigned)time(nullptr));
            randomizedQuickSort(arr, 0, n - 1);

            cout << "Sorted array: ";
            for (int x : arr) cout << x << " ";
            cout << "\n";
            break;
        }
        case 2: {
            long long n;
            int iterations;
            cout << "Enter number to test for primality: ";
            cin >> n;
            cout << "Enter number of iterations (rounds): ";
            cin >> iterations;

            srand((unsigned)time(nullptr));
            bool prime = fermatMonteCarloTest(n, iterations);
            cout << n << " is " << (prime ? "PROBABLY PRIME" : "COMPOSITE") << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 5 =====\n";
        cout << "1. Generate Permutations and Combinations\n";
        cout << "2. Probabilistic and Randomized Algorithms\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: permutationsAndCombinations(); break;
            case 2: randomizedAlgorithms();         break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
