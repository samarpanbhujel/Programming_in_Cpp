/*
 * Assignment 3 - Question 1
 * Program to generate truth tables of compound propositions built from
 * two propositional variables p and q using AND, OR, NOT, IMPLIES (->),
 * and BICONDITIONAL (<->).
 */
#include <iostream>
#include <iomanip>
using namespace std;

bool AND(bool a, bool b) { return a && b; }
bool OR(bool a, bool b)  { return a || b; }
bool NOT(bool a)         { return !a; }
bool IMPLIES(bool a, bool b) { return (!a) || b; }
bool BICONDITIONAL(bool a, bool b) { return a == b; }

void printRow(bool p, bool q) {
    cout << setw(6) << p << setw(6) << q
         << setw(10) << AND(p, q)
         << setw(10) << OR(p, q)
         << setw(10) << NOT(p)
         << setw(12) << IMPLIES(p, q)
         << setw(12) << BICONDITIONAL(p, q) << endl;
}

void fullTruthTable() {
    cout << setw(6) << "p" << setw(6) << "q"
         << setw(10) << "p^q" << setw(10) << "pVq"
         << setw(10) << "~p" << setw(12) << "p->q"
         << setw(12) << "p<->q" << endl;
    printRow(true, true);
    printRow(true, false);
    printRow(false, true);
    printRow(false, false);
}

int main() {
    int choice;
    do {
        cout << "\n--- Truth Table Menu ---\n";
        cout << "1. Generate truth table for p, q and compound propositions\n";
        cout << "   (p AND q, p OR q, NOT p, p -> q, p <-> q)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fullTruthTable();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
