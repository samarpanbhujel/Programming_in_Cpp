// Programs to implement set operations: union, intersection, difference, and Cartesian product.
#include <iostream>
#include <vector>
using namespace std;

bool contains(vector<int> set, int value) {
    for (int x : set) {
        if (x == value)
            return true;
    }
    return false;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    // Union
    cout << "Union: ";
    for (int x : A)
        cout << x << " ";

    for (int x : B) {
        if (!contains(A, x))
            cout << x << " ";
    }

    // Intersection
    cout << "\nIntersection: ";
    for (int x : A) {
        if (contains(B, x))
            cout << x << " ";
    }

    // Difference A - B
    cout << "\nDifference (A - B): ";
    for (int x : A) {
        if (!contains(B, x))
            cout << x << " ";
    }

    // Difference B - A
    cout << "\nDifference (B - A): ";
    for (int x : B) {
        if (!contains(A, x))
            cout << x << " ";
    }

    // Cartesian Product
    cout << "\nCartesian Product (A x B):\n";
    for (int x : A) {
        for (int y : B) {
            cout << "(" << x << ", " << y << ") ";
        }
    }

    return 0;
}