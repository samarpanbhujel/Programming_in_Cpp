// Write a program to create a class Employee with data members name, age and salary. 
// Create an array of Employee objects. Read values from the keyboard and 
// then print only those employees whose salary is greater than Rs. 50,000 and 
// whose employee name starts by "R". Using dynamic memory allocation. 
#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int age;
    double salary;

    void input() {
        cout << "Enter name: ";
        getline(cin >> ws, name);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    // Dynamic memory allocation
    Employee *employees = new Employee[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << endl;
        employees[i].input();
    }

    // Display employees satisfying the condition
    cout << "\nEmployees satisfying the condition:\n";

    for (int i = 0; i < n; i++) {

        if (employees[i].salary > 50000 &&
            employees[i].name[0] == 'R') {

            employees[i].display();
            cout << endl;
        }
    }

    // Release memory
    delete[] employees;

    return 0;
}