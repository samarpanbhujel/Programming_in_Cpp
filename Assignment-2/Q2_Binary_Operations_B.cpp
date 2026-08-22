// Binary Multiplication
#include <iostream>
#include <string>
using namespace std;

int binaryToDecimal(string binary) {

    int decimal = 0;

    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}

string decimalToBinary(int number) {

    if (number == 0)
        return "0";

    string binary = "";

    while (number > 0) {
        binary = char((number % 2) + '0') + binary;
        number /= 2;
    }

    return binary;
}

int main() {

    string a, b;

    cout << "Enter first binary number: ";
    cin >> a;

    cout << "Enter second binary number: ";
    cin >> b;

    int num1 = binaryToDecimal(a);
    int num2 = binaryToDecimal(b);

    int result = num1 * num2;

    cout << "Binary Multiplication = "
         << decimalToBinary(result) << endl;

    return 0;
}