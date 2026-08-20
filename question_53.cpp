// Write a program to dynamically allocate memory for a structure and input its members from user.
#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    // Dynamically allocating memory for a structure using 'new'
    Student* s1 = new Student();

    cout << "Enter name: ";
    cin >> s1->name;

    cout << "Enter age: ";
    cin >> s1->age;

    cout << "Enter marks: ";
    cin >> s1->marks;

    cout << "\n--- Student Details ---" << endl;
    cout << "Name: " << s1->name << endl;
    cout << "Age: " << s1->age << endl;
    cout << "Marks: " << s1->marks << endl;

    // Free the dynamically allocated memory
    delete s1;

    return 0;
}