/*
 * Assignment 2 - Question 4
 * Program to perform operations (addition, subtraction, multiplication)
 * on large integers by breaking them down into a set/array of small
 * single digits, since they are too large to fit in a normal int/long long.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Break a number string into a vector of digits (least significant first)
vector<int> toDigits(const string &num) {
    vector<int> digits;
    for (int i = num.size() - 1; i >= 0; i--)
        digits.push_back(num[i] - '0');
    return digits;
}

string toNumberString(vector<int> digits) {
    while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    string s;
    for (int i = digits.size() - 1; i >= 0; i--) s += char('0' + digits[i]);
    return s;
}

bool isSmaller(const vector<int> &a, const vector<int> &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

vector<int> addDigits(vector<int> a, vector<int> b) {
    vector<int> result;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    a.resize(n, 0); b.resize(n, 0);
    for (size_t i = 0; i < n; i++) {
        int sum = a[i] + b[i] + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry) result.push_back(carry);
    return result;
}

vector<int> subtractDigits(vector<int> a, vector<int> b) {
    // assumes a >= b
    vector<int> result;
    int borrow = 0;
    b.resize(a.size(), 0);
    for (size_t i = 0; i < a.size(); i++) {
        int diff = a[i] - b[i] - borrow;
        if (diff < 0) { diff += 10; borrow = 1; } else borrow = 0;
        result.push_back(diff);
    }
    return result;
}

vector<int> multiplyDigits(const vector<int> &a, const vector<int> &b) {
    vector<int> result(a.size() + b.size(), 0);
    for (size_t i = 0; i < a.size(); i++) {
        int carry = 0;
        for (size_t j = 0; j < b.size(); j++) {
            int prod = result[i + j] + a[i] * b[j] + carry;
            result[i + j] = prod % 10;
            carry = prod / 10;
        }
        size_t k = i + b.size();
        while (carry) {
            int sum = result[k] + carry;
            result[k] = sum % 10;
            carry = sum / 10;
            k++;
        }
    }
    return result;
}

int main() {
    string a, b;
    cout << "Enter first large positive integer: ";
    cin >> a;
    cout << "Enter second large positive integer: ";
    cin >> b;

    int choice;
    do {
        cout << "\n--- Large Integer Operations Menu ---\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction (larger - smaller)\n";
        cout << "3. Multiplication\n";
        cout << "4. Enter new numbers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        vector<int> da = toDigits(a), db = toDigits(b);

        switch (choice) {
            case 1:
                cout << a << " + " << b << " = "
                     << toNumberString(addDigits(da, db)) << endl;
                break;
            case 2:
                if (isSmaller(da, db))
                    cout << b << " - " << a << " = "
                         << toNumberString(subtractDigits(db, da))
                         << " (negative result shown as its magnitude)\n";
                else
                    cout << a << " - " << b << " = "
                         << toNumberString(subtractDigits(da, db)) << endl;
                break;
            case 3:
                cout << a << " * " << b << " = "
                     << toNumberString(multiplyDigits(da, db)) << endl;
                break;
            case 4:
                cout << "Enter first large positive integer: ";
                cin >> a;
                cout << "Enter second large positive integer: ";
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
