// Write a C++ program to append new data to an existing text file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("student.txt", ios::app);

    if (!file) {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    file << "\nThis is new data added to the file.";

    file.close();

    cout << "Data appended successfully." << endl;

    return 0;
}