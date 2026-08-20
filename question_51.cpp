// Write a program to dynamically allocate an array of integers & strings and initialize its elements.

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamically allocate integer array
    int* numbers = new int[n];

    // Dynamically allocate string array
    string* names = new string[n];

    // Initialize integer array
    cout << "\nEnter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Initialize string array
    cout << "\nEnter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    // Display the arrays
    cout << "\nInteger elements:\n";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\n\nString elements:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }

    // Free dynamically allocated memory
    delete[] numbers;
    delete[] names;

    return 0;
}