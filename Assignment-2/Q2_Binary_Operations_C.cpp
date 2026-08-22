// Binary Division
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

    cout << "Enter dividend in binary: ";
    cin >> a;

    cout << "Enter divisor in binary: ";
    cin >> b;

    int dividend = binaryToDecimal(a);
    int divisor = binaryToDecimal(b);

    if (divisor == 0) {
        cout << "Division by zero is not allowed.";
        return 0;
    }

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    cout << "Quotient = "
         << decimalToBinary(quotient) << endl;

    cout << "Remainder = "
         << decimalToBinary(remainder) << endl;

    return 0;
}