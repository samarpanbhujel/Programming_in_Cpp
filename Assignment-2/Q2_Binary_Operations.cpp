// Programs to implement binary integer addition, multiplication, and division.
#include <iostream>
#include <string>
using namespace std;

string binaryAddition(string a, string b) {

    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        result = char((sum % 2) + '0') + result;

        carry = sum / 2;
    }

    return result;
}

int main() {

    string a, b;

    cout << "Enter first binary number: ";
    cin >> a;

    cout << "Enter second binary number: ";
    cin >> b;

    cout << "Binary Addition = "
         << binaryAddition(a, b) << endl;

    return 0;
}