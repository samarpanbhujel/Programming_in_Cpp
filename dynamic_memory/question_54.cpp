// Define a base class Shape having data member radius. Derive two classes Circle and Sphere. 
// Write methods to compute the area of circle and sphere with Dynamic Memory Allocation.

#include <iostream>
using namespace std;

class Shape {
protected:
    float radius;

public:
    Shape(float r) {
        radius = r;
    }
};

class Circle : public Shape {
public:
    Circle(float r) : Shape(r) {}

    void area() {
        cout << "Area of Circle = " << 3.14159 * radius * radius << endl;
    }
};

class Sphere : public Shape {
public:
    Sphere(float r) : Shape(r) {}

    void area() {
        cout << "Surface Area of Sphere = " << 4 * 3.14159 * radius * radius << endl;
    }
};

int main() {
    Circle *c = new Circle(5);
    Sphere *s = new Sphere(5);

    c->area();
    s->area();

    delete c;
    delete s;

    return 0;
}