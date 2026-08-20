// Write a program to create an object of a class using new operator.

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Method to display student info
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Creating an object of Student class using 'new' operator
    Student* s1 = new Student();

    // Accessing members via pointer (arrow operator)
    s1->name = "Samarpan";
    s1->age = 21;

    // Calling method using the object
    s1->display();

    // Free the memory manually
    delete s1;

    return 0;
}