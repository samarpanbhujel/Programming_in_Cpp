// Write a program to create an object of a class using new operator.

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Constructor - runs automatically when object is created
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Dynamically creating an object using 'new', passing values to constructor
    Student* s1 = new Student("Samarpan", 21);

    // Calling method through the pointer
    s1->display();

    // Free the dynamically allocated memory
    delete s1;

    return 0;
}