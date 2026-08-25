/*
 * Assignment 2 - Question 3
 * Program to implement Boolean matrix operations: join (OR), meet
 * (AND, also called "product" of Boolean matrices elementwise), and
 * Boolean product (matrix multiplication using OR/AND).
 */
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix readMatrix(int rows, int cols, const string &name) {
    Matrix m(rows, vector<int>(cols));
    cout << "Enter elements (0 or 1) of matrix " << name << " ("
         << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];
    return m;
}

void printMatrix(const Matrix &m) {
    for (const auto &row : m) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
}

Matrix booleanJoin(const Matrix &a, const Matrix &b) {
    int r = a.size(), c = a[0].size();
    Matrix result(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            result[i][j] = a[i][j] | b[i][j];
    return result;
}

Matrix booleanMeet(const Matrix &a, const Matrix &b) {
    int r = a.size(), c = a[0].size();
    Matrix result(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            result[i][j] = a[i][j] & b[i][j];
    return result;
}

// Boolean product: result[i][j] = OR over k of (a[i][k] AND b[k][j])
Matrix booleanProduct(const Matrix &a, const Matrix &b) {
    int r = a.size(), inner = b.size(), c = b[0].size();
    Matrix result(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            for (int k = 0; k < inner; k++)
                result[i][j] |= (a[i][k] & b[k][j]);
    return result;
}

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;
    Matrix A = readMatrix(r1, c1, "A");

    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;
    Matrix B = readMatrix(r2, c2, "B");

    int choice;
    do {
        cout << "\n--- Boolean Matrix Operations Menu ---\n";
        cout << "1. Join (A OR B)  [requires same dimensions]\n";
        cout << "2. Meet (A AND B) [requires same dimensions]\n";
        cout << "3. Boolean Product (A x B) [requires cols(A) = rows(B)]\n";
        cout << "4. Display matrices A and B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (r1 != r2 || c1 != c2) {
                    cout << "Error: matrices must have the same dimensions.\n";
                } else {
                    cout << "A JOIN B =\n";
                    printMatrix(booleanJoin(A, B));
                }
                break;
            case 2:
                if (r1 != r2 || c1 != c2) {
                    cout << "Error: matrices must have the same dimensions.\n";
                } else {
                    cout << "A MEET B =\n";
                    printMatrix(booleanMeet(A, B));
                }
                break;
            case 3:
                if (c1 != r2) {
                    cout << "Error: columns of A must equal rows of B.\n";
                } else {
                    cout << "A (Boolean product) B =\n";
                    printMatrix(booleanProduct(A, B));
                }
                break;
            case 4:
                cout << "Matrix A:\n"; printMatrix(A);
                cout << "Matrix B:\n"; printMatrix(B);
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
