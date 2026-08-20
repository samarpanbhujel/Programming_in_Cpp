// Write a C++ program to count the number of lines in a text file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("student.txt");

    if (!file) {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        count++;
    }

    cout << "Number of lines in the file: " << count << endl;

    file.close();

    return 0;
}