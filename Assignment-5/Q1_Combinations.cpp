// Combination
#include <iostream>
#include <string>
using namespace std;

void combination(string str, string result, int index, int r) {

    if (result.length() == r) {
        cout << result << endl;
        return;
    }

    if (index == str.length())
        return;

    // Include current character
    combination(str, result + str[index], index + 1, r);

    // Don't include current character
    combination(str, result, index + 1, r);
}

int main() {

    string str;
    int r;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter number of elements to choose: ";
    cin >> r;

    cout << "\nCombinations are:\n";

    combination(str, "", 0, r);

    return 0;
}