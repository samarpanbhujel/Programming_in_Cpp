/*
 * Assignment 6 - Question 1
 * Program to represent a relation on a set as a Boolean matrix, test
 * its properties (reflexive, symmetric, antisymmetric, transitive),
 * and test whether it is an equivalence relation.
 */
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

bool isReflexive(const Matrix &R, int n) {
    for (int i = 0; i < n; i++)
        if (R[i][i] != 1) return false;
    return true;
}

bool isSymmetric(const Matrix &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (R[i][j] != R[j][i]) return false;
    return true;
}

bool isAntisymmetric(const Matrix &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && R[i][j] == 1 && R[j][i] == 1) return false;
    return true;
}

bool isTransitive(const Matrix &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (R[i][j] == 1)
                for (int k = 0; k < n; k++)
                    if (R[j][k] == 1 && R[i][k] != 1) return false;
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements in the set (elements labeled 0..n-1): ";
    cin >> n;

    Matrix R(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n
         << " relation matrix (1 if (i,j) is in R, else 0):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> R[i][j];

    int choice;
    do {
        cout << "\n--- Relations Menu ---\n";
        cout << "1. Check Reflexive\n";
        cout << "2. Check Symmetric\n";
        cout << "3. Check Antisymmetric\n";
        cout << "4. Check Transitive\n";
        cout << "5. Check Equivalence Relation (reflexive+symmetric+transitive)\n";
        cout << "6. Display relation matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Reflexive: " << (isReflexive(R, n) ? "Yes" : "No") << endl;
                break;
            case 2:
                cout << "Symmetric: " << (isSymmetric(R, n) ? "Yes" : "No") << endl;
                break;
            case 3:
                cout << "Antisymmetric: " << (isAntisymmetric(R, n) ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Transitive: " << (isTransitive(R, n) ? "Yes" : "No") << endl;
                break;
            case 5: {
                bool eq = isReflexive(R, n) && isSymmetric(R, n) && isTransitive(R, n);
                cout << "Equivalence Relation: " << (eq ? "Yes" : "No") << endl;
                break;
            }
            case 6:
                for (const auto &row : R) {
                    for (int v : row) cout << v << " ";
                    cout << endl;
                }
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
