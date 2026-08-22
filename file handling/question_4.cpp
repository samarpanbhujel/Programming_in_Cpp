// Write a C++ program to count the number of words in a text file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("student.txt");

    if (!file) {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    string word;
    int count = 0;

    while (file >> word) {
        count++;
    }

    cout << "Number of words in the file: " << count << endl;

    file.close();

    return 0;
}