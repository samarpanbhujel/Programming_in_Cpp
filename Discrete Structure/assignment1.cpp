/*
    Assignment 1
    1. Set operations: union, intersection, difference, Cartesian product
    2. Ceiling and floor functions
    3. Fuzzy set operations
*/
#include <bits/stdc++.h>
using namespace std;

void setOperations() {
    int n1, n2;
    cout << "Enter size of set A: "; cin >> n1;
    vector<int> A(n1);
    cout << "Enter elements of A: ";
    for (int i = 0; i < n1; i++) cin >> A[i];

    cout << "Enter size of set B: "; cin >> n2;
    vector<int> B(n2);
    cout << "Enter elements of B: ";
    for (int i = 0; i < n2; i++) cin >> B[i];

    set<int> setA(A.begin(), A.end());
    set<int> setB(B.begin(), B.end());

    int choice;
    cout << "\n--- Set Operations ---\n";
    cout << "1. Union\n2. Intersection\n3. Difference (A-B)\n4. Cartesian Product\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            set<int> result;
            set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                      inserter(result, result.begin()));
            cout << "A U B = { ";
            for (int x : result) cout << x << " ";
            cout << "}\n";
            break;
        }
        case 2: {
            set<int> result;
            set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                              inserter(result, result.begin()));
            cout << "A n B = { ";
            for (int x : result) cout << x << " ";
            cout << "}\n";
            break;
        }
        case 3: {
            set<int> result;
            set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                            inserter(result, result.begin()));
            cout << "A - B = { ";
            for (int x : result) cout << x << " ";
            cout << "}\n";
            break;
        }
        case 4: {
            cout << "A x B = { ";
            for (int a : setA)
                for (int b : setB)
                    cout << "(" << a << "," << b << ") ";
            cout << "}\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

void ceilingFloor() {
    double x;
    cout << "Enter a real number: ";
    cin >> x;
    cout << "Floor(" << x << ")   = " << floor(x) << "\n";
    cout << "Ceiling(" << x << ") = " << ceil(x) << "\n";
}

void fuzzySetOperations() {
    int n;
    cout << "Enter number of elements in the fuzzy sets: ";
    cin >> n;
    vector<double> A(n), B(n);
    cout << "Enter membership values of fuzzy set A (0 to 1): ";
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << "Enter membership values of fuzzy set B (0 to 1): ";
    for (int i = 0; i < n; i++) cin >> B[i];

    int choice;
    cout << "\n--- Fuzzy Set Operations ---\n";
    cout << "1. Union (max)\n2. Intersection (min)\n3. Complement of A\n4. Difference (A-B)\n";
    cout << "Enter choice: ";
    cin >> choice;

    vector<double> result(n);
    switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) result[i] = max(A[i], B[i]);
            cout << "A U B = ";
            for (double x : result) cout << x << " ";
            cout << "\n";
            break;
        case 2:
            for (int i = 0; i < n; i++) result[i] = min(A[i], B[i]);
            cout << "A n B = ";
            for (double x : result) cout << x << " ";
            cout << "\n";
            break;
        case 3:
            for (int i = 0; i < n; i++) result[i] = 1.0 - A[i];
            cout << "A' = ";
            for (double x : result) cout << x << " ";
            cout << "\n";
            break;
        case 4:
            for (int i = 0; i < n; i++) result[i] = min(A[i], 1.0 - B[i]);
            cout << "A - B = ";
            for (double x : result) cout << x << " ";
            cout << "\n";
            break;
        default:
            cout << "Invalid choice\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 1 =====\n";
        cout << "1. Set Operations (Union, Intersection, Difference, Cartesian Product)\n";
        cout << "2. Ceiling and Floor Functions\n";
        cout << "3. Fuzzy Set Operations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: setOperations();      break;
            case 2: ceilingFloor();       break;
            case 3: fuzzySetOperations(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
