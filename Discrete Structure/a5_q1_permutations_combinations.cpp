/*
 * Assignment 5 - Question 1
 * Program to generate permutations and combinations of a set of
 * distinct elements entered by the user.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> elements;

void printVector(const vector<int> &v) {
    cout << "( ";
    for (int x : v) cout << x << " ";
    cout << ")\n";
}

// Generate all permutations using recursive swapping
void generatePermutations(vector<int> &arr, int l) {
    if (l == (int)arr.size() - 1) {
        printVector(arr);
        return;
    }
    for (int i = l; i < (int)arr.size(); i++) {
        swap(arr[l], arr[i]);
        generatePermutations(arr, l + 1);
        swap(arr[l], arr[i]);
    }
}

// Generate all r-combinations of elements[0..n-1]
void generateCombinations(int n, int r, int start, vector<int> &current) {
    if ((int)current.size() == r) {
        printVector(current);
        return;
    }
    for (int i = start; i < n; i++) {
        current.push_back(elements[i]);
        generateCombinations(n, r, i + 1, current);
        current.pop_back();
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    elements.resize(n);
    cout << "Enter " << n << " distinct elements: ";
    for (int i = 0; i < n; i++) cin >> elements[i];

    int choice;
    do {
        cout << "\n--- Permutations / Combinations Menu ---\n";
        cout << "1. Generate all permutations\n";
        cout << "2. Generate all r-combinations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                vector<int> arr = elements;
                cout << "All permutations:\n";
                generatePermutations(arr, 0);
                break;
            }
            case 2: {
                int r;
                cout << "Enter value of r (r <= n): ";
                cin >> r;
                if (r < 0 || r > n) {
                    cout << "Invalid r.\n";
                    break;
                }
                vector<int> current;
                cout << "All " << r << "-combinations:\n";
                generateCombinations(n, r, 0, current);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
