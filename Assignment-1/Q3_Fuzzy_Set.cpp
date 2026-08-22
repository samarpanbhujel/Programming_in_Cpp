// Programs to implement fuzzy set operations.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    double A[n], B[n];

    cout << "Enter membership values of Set A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter membership values of Set B:\n";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Fuzzy Union
    cout << "\nFuzzy Union:\n";
    for (int i = 0; i < n; i++) {
        cout << max(A[i], B[i]) << " ";
    }

    // Fuzzy Intersection
    cout << "\nFuzzy Intersection:\n";
    for (int i = 0; i < n; i++) {
        cout << min(A[i], B[i]) << " ";
    }

    // Fuzzy Complement of A
    cout << "\nFuzzy Complement of A:\n";
    for (int i = 0; i < n; i++) {
        cout << 1 - A[i] << " ";
    }

    // Fuzzy Complement of B
    cout << "\nFuzzy Complement of B:\n";
    for (int i = 0; i < n; i++) {
        cout << 1 - B[i] << " ";
    }

    return 0;
}