// Programs to implement Boolean matrix operations: join, product, and Boolean product.
#include <iostream>
using namespace std;

int main() {

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int A[10][10], B[10][10];

    cout << "\nEnter Matrix A:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter Matrix B:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
        }
    }

    // JOIN
    cout << "\nJoin (A OR B):\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << (A[i][j] || B[i][j]) << " ";
        }
        cout << endl;
    }

    // PRODUCT / MEET
    cout << "\nProduct (A AND B):\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << (A[i][j] && B[i][j]) << " ";
        }
        cout << endl;
    }

    // BOOLEAN PRODUCT
    // A and B must be compatible for matrix multiplication
    cout << "\nBoolean Product (A * B):\n";

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            int result = 0;

            for (int k = 0; k < cols; k++) {
                result = result || (A[i][k] && B[k][j]);
            }

            cout << result << " ";
        }

        cout << endl;
    }

    return 0;
}