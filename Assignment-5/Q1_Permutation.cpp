// Permutation
#include <iostream>
#include <string>
using namespace std;

void permutation(string str, int left, int right) {

    if (left == right) {
        cout << str << endl;
        return;
    }

    for (int i = left; i <= right; i++) {

        swap(str[left], str[i]);

        permutation(str, left + 1, right);

        // Backtrack
        swap(str[left], str[i]);
    }
}

int main() {

    string str;

    cout << "Enter a string: ";
    cin >> str;

    cout << "\nPermutations are:\n";

    permutation(str, 0, str.length() - 1);

    return 0;
}