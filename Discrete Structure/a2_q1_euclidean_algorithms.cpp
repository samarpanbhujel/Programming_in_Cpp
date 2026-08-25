/*
 * Assignment 2 - Question 1
 * Program to implement the Euclidean algorithm (GCD) and the
 * Extended Euclidean algorithm (GCD + Bezout coefficients x, y
 * such that a*x + b*y = gcd(a,b)).
 */
#include <iostream>
using namespace std;

int gcdEuclidean(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Returns gcd(a,b) and sets x, y such that a*x + b*y = gcd(a,b)
int extendedEuclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    int a, b;
    cout << "Enter two integers a and b: ";
    cin >> a >> b;

    int choice;
    do {
        cout << "\n--- Euclidean Algorithm Menu ---\n";
        cout << "1. Euclidean Algorithm (GCD)\n";
        cout << "2. Extended Euclidean Algorithm (GCD + coefficients)\n";
        cout << "3. Enter new values of a, b\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "GCD(" << a << ", " << b << ") = "
                     << gcdEuclidean(a, b) << endl;
                break;
            case 2: {
                int x, y;
                int g = extendedEuclidean(a, b, x, y);
                cout << "GCD(" << a << ", " << b << ") = " << g << endl;
                cout << "Coefficients: x = " << x << ", y = " << y
                     << ", such that "
                     << a << "*(" << x << ") + " << b << "*(" << y
                     << ") = " << g << endl;
                break;
            }
            case 3:
                cout << "Enter two integers a and b: ";
                cin >> a >> b;
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
