/*
 * Assignment 1 - Question 3
 * Program to implement fuzzy set operations: union, intersection,
 * complement, and difference (membership values in range [0,1]).
 */
#include <iostream>
#include <vector>
using namespace std;

vector<double> readFuzzySet(const string &name, int n) {
    vector<double> s(n);
    cout << "Enter " << n << " membership values (0 to 1) for fuzzy set "
         << name << ": ";
    for (int i = 0; i < n; i++) cin >> s[i];
    return s;
}

void printFuzzySet(const vector<double> &s) {
    cout << "{ ";
    for (double x : s) cout << x << " ";
    cout << "}\n";
}

vector<double> fuzzyUnion(const vector<double> &a, const vector<double> &b) {
    vector<double> r(a.size());
    for (size_t i = 0; i < a.size(); i++) r[i] = max(a[i], b[i]);
    return r;
}

vector<double> fuzzyIntersection(const vector<double> &a, const vector<double> &b) {
    vector<double> r(a.size());
    for (size_t i = 0; i < a.size(); i++) r[i] = min(a[i], b[i]);
    return r;
}

vector<double> fuzzyComplement(const vector<double> &a) {
    vector<double> r(a.size());
    for (size_t i = 0; i < a.size(); i++) r[i] = 1.0 - a[i];
    return r;
}

vector<double> fuzzyDifference(const vector<double> &a, const vector<double> &b) {
    // A - B = A intersection complement(B)
    vector<double> compB = fuzzyComplement(b);
    return fuzzyIntersection(a, compB);
}

int main() {
    int n;
    cout << "Enter number of elements in the universe: ";
    cin >> n;

    vector<double> A = readFuzzySet("A", n);
    vector<double> B = readFuzzySet("B", n);

    int choice;
    do {
        cout << "\n--- Fuzzy Set Operations Menu ---\n";
        cout << "1. Union (A U B)\n";
        cout << "2. Intersection (A ^ B)\n";
        cout << "3. Complement of A\n";
        cout << "4. Complement of B\n";
        cout << "5. Difference (A - B)\n";
        cout << "6. Display sets A and B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "A U B = ";
                printFuzzySet(fuzzyUnion(A, B));
                break;
            case 2:
                cout << "A ^ B = ";
                printFuzzySet(fuzzyIntersection(A, B));
                break;
            case 3:
                cout << "A' = ";
                printFuzzySet(fuzzyComplement(A));
                break;
            case 4:
                cout << "B' = ";
                printFuzzySet(fuzzyComplement(B));
                break;
            case 5:
                cout << "A - B = ";
                printFuzzySet(fuzzyDifference(A, B));
                break;
            case 6:
                cout << "A = "; printFuzzySet(A);
                cout << "B = "; printFuzzySet(B);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
