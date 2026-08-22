// write a program to create a new text file and write your name and address text into it.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("student.txt");

    file << "Name: Samarpan Bhujel" << endl;
    file << "Address: Kathmandu, Nepal" << endl;

    file.close();

    cout << "Data written successfully!" << endl;

    return 0;
}