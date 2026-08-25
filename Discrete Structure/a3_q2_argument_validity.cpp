/*
 * Assignment 3 - Question 2
 * Program to test the validity of arguments by using truth tables.
 * An argument (premises -> conclusion) is VALID if, in every row of
 * the truth table where all premises are true, the conclusion is also
 * true. This program checks validity for four classic argument forms
 * over propositional variables p, q, r.
 */
#include <iostream>
#include <iomanip>
using namespace std;

bool IMPLIES(bool a, bool b) { return (!a) || b; }

// Checks validity of an argument given arrays of premise truth values
// and the conclusion truth value, printed row by row for all 8
// combinations of p, q, r.
void checkValidity(const string &name,
                    bool (*premise1)(bool, bool, bool),
                    bool (*premise2)(bool, bool, bool),
                    bool (*conclusion)(bool, bool, bool)) {
    cout << "\nArgument: " << name << "\n";
    cout << setw(4) << "p" << setw(4) << "q" << setw(4) << "r"
         << setw(10) << "Prem1" << setw(10) << "Prem2"
         << setw(10) << "Concl" << endl;

    bool valid = true;
    for (int i = 0; i < 8; i++) {
        bool p = i & 4, q = i & 2, r = i & 1;
        bool pr1 = premise1(p, q, r);
        bool pr2 = premise2(p, q, r);
        bool con = conclusion(p, q, r);
        cout << setw(4) << p << setw(4) << q << setw(4) << r
             << setw(10) << pr1 << setw(10) << pr2
             << setw(10) << con << endl;
        if (pr1 && pr2 && !con) valid = false;
    }
    cout << "Result: The argument is " << (valid ? "VALID" : "INVALID") << endl;
}

// Modus Ponens: p->q, p |- q
bool mp_prem1(bool p, bool q, bool r) { return IMPLIES(p, q); }
bool mp_prem2(bool p, bool q, bool r) { return p; }
bool mp_concl(bool p, bool q, bool r) { return q; }

// Modus Tollens: p->q, ~q |- ~p
bool mt_prem1(bool p, bool q, bool r) { return IMPLIES(p, q); }
bool mt_prem2(bool p, bool q, bool r) { return !q; }
bool mt_concl(bool p, bool q, bool r) { return !p; }

// Hypothetical Syllogism: p->q, q->r |- p->r
bool hs_prem1(bool p, bool q, bool r) { return IMPLIES(p, q); }
bool hs_prem2(bool p, bool q, bool r) { return IMPLIES(q, r); }
bool hs_concl(bool p, bool q, bool r) { return IMPLIES(p, r); }

// Disjunctive Syllogism: p V q, ~p |- q
bool ds_prem1(bool p, bool q, bool r) { return p || q; }
bool ds_prem2(bool p, bool q, bool r) { return !p; }
bool ds_concl(bool p, bool q, bool r) { return q; }

int main() {
    int choice;
    do {
        cout << "\n--- Argument Validity Menu ---\n";
        cout << "1. Modus Ponens (p->q, p |- q)\n";
        cout << "2. Modus Tollens (p->q, ~q |- ~p)\n";
        cout << "3. Hypothetical Syllogism (p->q, q->r |- p->r)\n";
        cout << "4. Disjunctive Syllogism (p V q, ~p |- q)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkValidity("Modus Ponens", mp_prem1, mp_prem2, mp_concl);
                break;
            case 2:
                checkValidity("Modus Tollens", mt_prem1, mt_prem2, mt_concl);
                break;
            case 3:
                checkValidity("Hypothetical Syllogism", hs_prem1, hs_prem2, hs_concl);
                break;
            case 4:
                checkValidity("Disjunctive Syllogism", ds_prem1, ds_prem2, ds_concl);
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
