/*
 * Assignment 1 - Question 2
 * Program to implement ceiling and floor functions (without using
 * the built-in ceil()/floor() library functions).
 */
#include <iostream>
using namespace std;

// Floor: largest integer <= x
int myFloor(double x) {
    int intPart = (int)x;
    if (x < 0 && x != intPart)
        return intPart - 1;
    return intPart;
}

// Ceiling: smallest integer >= x
int myCeil(double x) {
    int intPart = (int)x;
    if (x > 0 && x != intPart)
        return intPart + 1;
    return intPart;
}

int main() {
    double x;
    cout << "Enter a real number: ";
    cin >> x;

    int choice;
    do {
        cout << "\n--- Ceiling / Floor Menu ---\n";
        cout << "1. Compute Floor(x)\n";
        cout << "2. Compute Ceiling(x)\n";
        cout << "3. Enter a new number\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Floor(" << x << ") = " << myFloor(x) << endl;
                break;
            case 2:
                cout << "Ceiling(" << x << ") = " << myCeil(x) << endl;
                break;
            case 3:
                cout << "Enter a real number: ";
                cin >> x;
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
