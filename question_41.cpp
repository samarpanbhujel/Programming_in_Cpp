// write a program to open an existing text file and display its contents on monitor
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

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}