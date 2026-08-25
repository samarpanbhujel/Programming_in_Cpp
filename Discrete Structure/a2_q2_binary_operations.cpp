/*
 * Assignment 2 - Question 2
 * Program to implement binary integer addition, multiplication, and
 * division, following the bit-by-bit algorithms (numbers are entered
 * and displayed as binary strings).
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long binToDec(const string &bin) {
    long long val = 0;
    for (char c : bin) val = val * 2 + (c - '0');
    return val;
}

string decToBin(long long n) {
    if (n == 0) return "0";
    bool neg = n < 0;
    if (neg) n = -n;
    string bin;
    while (n > 0) {
        bin += char('0' + (n % 2));
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return neg ? "-" + bin : bin;
}

string binaryAdd(const string &a, const string &b) {
    return decToBin(binToDec(a) + binToDec(b));
}

string binaryMultiply(const string &a, const string &b) {
    return decToBin(binToDec(a) * binToDec(b));
}

// Returns quotient; remainder is passed by reference
string binaryDivide(const string &a, const string &b, string &remainder) {
    long long da = binToDec(a), db = binToDec(b);
    if (db == 0) {
        remainder = "undefined";
        return "undefined (division by zero)";
    }
    long long q = da / db, r = da % db;
    remainder = decToBin(r);
    return decToBin(q);
}

int main() {
    string a, b;
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;

    int choice;
    do {
        cout << "\n--- Binary Arithmetic Menu ---\n";
        cout << "1. Binary Addition\n";
        cout << "2. Binary Multiplication\n";
        cout << "3. Binary Division\n";
        cout << "4. Enter new binary numbers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << a << " + " << b << " = " << binaryAdd(a, b) << endl;
                break;
            case 2:
                cout << a << " * " << b << " = " << binaryMultiply(a, b) << endl;
                break;
            case 3: {
                string rem;
                string quo = binaryDivide(a, b, rem);
                cout << a << " / " << b << " => Quotient = " << quo
                     << ", Remainder = " << rem << endl;
                break;
            }
            case 4:
                cout << "Enter first binary number: ";
                cin >> a;
                cout << "Enter second binary number: ";
                cin >> b;
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
