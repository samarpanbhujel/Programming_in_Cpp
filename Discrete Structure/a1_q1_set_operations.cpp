/*
 * Assignment 1 - Question 1
 * Program to implement set operations: union, intersection, difference,
 * and Cartesian product.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Read a set of integers from the user (duplicates removed)
vector<int> readSet(const string &name, int n) {
    vector<int> s;
    cout << "Enter " << n << " elements for set " << name << ": ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (find(s.begin(), s.end(), x) == s.end())
            s.push_back(x);
    }
    return s;
}

void printSet(const vector<int> &s) {
    cout << "{ ";
    for (int x : s) cout << x << " ";
    cout << "}\n";
}

vector<int> setUnion(vector<int> a, vector<int> b) {
    for (int x : b)
        if (find(a.begin(), a.end(), x) == a.end())
            a.push_back(x);
    return a;
}

vector<int> setIntersection(const vector<int> &a, const vector<int> &b) {
    vector<int> result;
    for (int x : a)
        if (find(b.begin(), b.end(), x) != b.end())
            result.push_back(x);
    return result;
}

vector<int> setDifference(const vector<int> &a, const vector<int> &b) {
    vector<int> result;
    for (int x : a)
        if (find(b.begin(), b.end(), x) == b.end())
            result.push_back(x);
    return result;
}

void cartesianProduct(const vector<int> &a, const vector<int> &b) {
    cout << "A x B = { ";
    for (int x : a)
        for (int y : b)
            cout << "(" << x << "," << y << ") ";
    cout << "}\n";
}

int main() {
    int n1, n2;
    cout << "Enter number of elements in set A: ";
    cin >> n1;
    vector<int> A = readSet("A", n1);

    cout << "Enter number of elements in set B: ";
    cin >> n2;
    vector<int> B = readSet("B", n2);

    int choice;
    do {
        cout << "\n--- Set Operations Menu ---\n";
        cout << "1. Union (A U B)\n";
        cout << "2. Intersection (A ^ B)\n";
        cout << "3. Difference (A - B)\n";
        cout << "4. Cartesian Product (A x B)\n";
        cout << "5. Display sets A and B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "A U B = ";
                printSet(setUnion(A, B));
                break;
            case 2:
                cout << "A ^ B = ";
                printSet(setIntersection(A, B));
                break;
            case 3:
                cout << "A - B = ";
                printSet(setDifference(A, B));
                break;
            case 4:
                cartesianProduct(A, B);
                break;
            case 5:
                cout << "A = "; printSet(A);
                cout << "B = "; printSet(B);
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
