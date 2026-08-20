// Write a program to dynamically allocate an integer, a float & a string and assign a value to them.
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Dynamically allocate memory
    int *i = new int;
    float *f = new float;
    string *s = new string;

    // Assign values
    *i = 10;
    *f = 25.5;
    *s = "Hello World";

    // Display values
    cout << "Integer: " << *i << endl;
    cout << "Float: " << *f << endl;
    cout << "String: " << *s << endl;

    // Free dynamically allocated memory
    delete i;
    delete f;
    delete s;

    return 0;
}