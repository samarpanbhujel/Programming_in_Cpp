// Write a base class called Person with attributes name and age. 
// Derive two classes Employee with attributes post and salary, and Student with attributes grade and gender. 
// Using these base and derived classes, write a program to display attributes 
// using dynamic memory allocation.

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Employee : public Person {
private:
    string post;
    float salary;

public:
    Employee(string n, int a, string p, float s)
        : Person(n, a) {
        post = p;
        salary = s;
    }

    void display() {
        cout << "Employee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Post: " << post << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Student : public Person {
private:
    string grade;
    string gender;

public:
    Student(string n, int a, string g, string gen)
        : Person(n, a) {
        grade = g;
        gender = gen;
    }

    void display() {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Gender: " << gender << endl;
    }
};

int main() {

    // Dynamic memory allocation
    Employee *e = new Employee("Ram", 30, "Manager", 50000);
    Student *s = new Student("Sita", 20, "A", "Female");

    e->display();
    s->display();

    // Free dynamically allocated memory
    delete e;
    delete s;

    return 0;
}
