/*
    Assignment 3
    1. Programs to generate truth tables of compound propositions
    2. Programs to test validity of arguments by using truth tables

    Expression syntax (variables restricted to p, q, r, s):
        ~  NOT     (unary, highest precedence)
        &  AND
        |  OR
        >  IMPLIES
        =  BICONDITIONAL   (lowest precedence)
        () parentheses allowed

    Example: (p & q) > r
*/
#include <bits/stdc++.h>
using namespace std;

// ---------- Recursive descent parser/evaluator for propositional formulas ----------
class Parser {
    string expr;
    int pos;
    map<char, bool> *values;

    void skipSpaces() {
        while (pos < (int)expr.size() && expr[pos] == ' ') pos++;
    }

    char peek() {
        skipSpaces();
        return pos < (int)expr.size() ? expr[pos] : '\0';
    }

    char get() {
        skipSpaces();
        return pos < (int)expr.size() ? expr[pos++] : '\0';
    }

    // Biconditional (lowest precedence)
    bool parseBiconditional() {
        bool left = parseImplies();
        while (peek() == '=') {
            get();
            bool right = parseImplies();
            left = (left == right);
        }
        return left;
    }

    // Implication
    bool parseImplies() {
        bool left = parseOr();
        while (peek() == '>') {
            get();
            bool right = parseOr();
            left = (!left) || right;
        }
        return left;
    }

    // Or
    bool parseOr() {
        bool left = parseAnd();
        while (peek() == '|') {
            get();
            bool right = parseAnd();
            left = left || right;
        }
        return left;
    }

    // And
    bool parseAnd() {
        bool left = parseNot();
        while (peek() == '&') {
            get();
            bool right = parseNot();
            left = left && right;
        }
        return left;
    }

    // Not (unary, right-associative)
    bool parseNot() {
        if (peek() == '~') {
            get();
            return !parseNot();
        }
        return parseAtom();
    }

    // Atom: variable or parenthesized expression
    bool parseAtom() {
        char c = peek();
        if (c == '(') {
            get();
            bool val = parseBiconditional();
            if (peek() == ')') get();
            return val;
        }
        c = get();
        return (*values)[c];
    }

public:
    bool evaluate(const string &e, map<char, bool> &vals) {
        expr = e;
        pos = 0;
        values = &vals;
        return parseBiconditional();
    }
};

set<char> extractVariables(const string &expr) {
    set<char> vars;
    for (char c : expr)
        if (c == 'p' || c == 'q' || c == 'r' || c == 's')
            vars.insert(c);
    return vars;
}

void printTruthTable(const string &expr) {
    set<char> varSet = extractVariables(expr);
    vector<char> vars(varSet.begin(), varSet.end());
    int n = vars.size();

    for (char v : vars) cout << v << "\t";
    cout << expr << "\n";

    Parser parser;
    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        map<char, bool> values;
        for (int i = 0; i < n; i++)
            values[vars[i]] = (mask >> (n - i - 1)) & 1;
        for (char v : vars) cout << values[v] << "\t";
        bool result = parser.evaluate(expr, values);
        cout << result << "\n";
    }
}

void generateTruthTable() {
    string expr;
    cout << "Enter a compound proposition (vars: p q r s, ops: ~ & | > =, use parentheses):\n";
    cin.ignore();
    getline(cin, expr);
    cout << "\n--- Truth Table ---\n";
    printTruthTable(expr);
}

void testArgumentValidity() {
    int n;
    cout << "Enter number of premises: ";
    cin >> n;
    cin.ignore();

    vector<string> premises(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter premise " << (i + 1) << ": ";
        getline(cin, premises[i]);
    }

    string conclusion;
    cout << "Enter the conclusion: ";
    getline(cin, conclusion);

    set<char> varSet;
    for (auto &p : premises)
        for (char c : p)
            if (c == 'p' || c == 'q' || c == 'r' || c == 's') varSet.insert(c);
    for (char c : conclusion)
        if (c == 'p' || c == 'q' || c == 'r' || c == 's') varSet.insert(c);

    vector<char> vars(varSet.begin(), varSet.end());
    int m = vars.size();
    Parser parser;
    bool valid = true;

    cout << "\n";
    for (char v : vars) cout << v << "\t";
    for (int i = 0; i < n; i++) cout << "P" << (i + 1) << "\t";
    cout << "C\n";

    for (int mask = (1 << m) - 1; mask >= 0; mask--) {
        map<char, bool> values;
        for (int i = 0; i < m; i++)
            values[vars[i]] = (mask >> (m - i - 1)) & 1;

        bool allPremisesTrue = true;
        for (char v : vars) cout << values[v] << "\t";
        for (auto &p : premises) {
            bool pv = parser.evaluate(p, values);
            cout << pv << "\t";
            allPremisesTrue = allPremisesTrue && pv;
        }
        bool cv = parser.evaluate(conclusion, values);
        cout << cv << "\n";

        if (allPremisesTrue && !cv) valid = false;
    }

    cout << "\nArgument is " << (valid ? "VALID" : "INVALID") << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 3 =====\n";
        cout << "1. Generate Truth Table of a Compound Proposition\n";
        cout << "2. Test Validity of an Argument using Truth Tables\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generateTruthTable();   break;
            case 2: testArgumentValidity(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
