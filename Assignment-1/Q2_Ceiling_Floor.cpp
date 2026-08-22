// Programs to implement ceiling and floor functions.
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Ceiling value: " << ceil(number) << endl;
    cout << "Floor value: " << floor(number) << endl;

    return 0;
}