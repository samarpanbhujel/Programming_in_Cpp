// Programs to perform operations with large integers by breaking them down into sets of small integers.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int BASE = 1000;

// Convert large integer string into blocks
vector<int> convertToBlocks(string number) {

    vector<int> blocks;

    for (int i = number.length(); i > 0; i -= 3) {

        int start = max(0, i - 3);

        int length = i - start;

        blocks.push_back(stoi(number.substr(start, length)));
    }

    return blocks;
}

// Display blocks as a large integer
void printNumber(vector<int> number) {

    cout << number.back();

    for (int i = number.size() - 2; i >= 0; i--) {
        cout << number[i] / 100;
        cout << (number[i] / 10) % 10;
        cout << number[i] % 10;
    }

    cout << endl;
}

// Addition
vector<int> add(vector<int> A, vector<int> B) {

    vector<int> result;

    int carry = 0;

    int n = max(A.size(), B.size());

    for (int i = 0; i < n; i++) {

        int sum = carry;

        if (i < A.size())
            sum += A[i];

        if (i < B.size())
            sum += B[i];

        result.push_back(sum % BASE);

        carry = sum / BASE;
    }

    if (carry)
        result.push_back(carry);

    return result;
}

// Multiplication
vector<int> multiply(vector<int> A, vector<int> B) {

    vector<int> result(A.size() + B.size(), 0);

    for (int i = 0; i < A.size(); i++) {

        int carry = 0;

        for (int j = 0; j < B.size(); j++) {

            int value = result[i + j]
                      + A[i] * B[j]
                      + carry;

            result[i + j] = value % BASE;

            carry = value / BASE;
        }

        result[i + B.size()] += carry;
    }

    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

int main() {

    string num1, num2;

    cout << "Enter first large integer: ";
    cin >> num1;

    cout << "Enter second large integer: ";
    cin >> num2;

    vector<int> A = convertToBlocks(num1);
    vector<int> B = convertToBlocks(num2);

    vector<int> sum = add(A, B);
    vector<int> product = multiply(A, B);

    cout << "\nAddition: ";
    printNumber(sum);

    cout << "Multiplication: ";
    printNumber(product);

    return 0;
}