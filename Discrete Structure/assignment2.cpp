/*
    Assignment 2
    1. Euclidean and Extended Euclidean algorithms
    2. Binary integer addition, multiplication, division
    3. Boolean matrix operations: join, meet(product), Boolean product
    4. Operations with large integers by breaking them into arrays of small digits
*/
#include <bits/stdc++.h>
using namespace std;

// ---------- 1. Euclidean / Extended Euclidean ----------
int gcdEuclid(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

void euclideanAlgorithms() {
    int a, b;
    cout << "Enter two integers a and b: ";
    cin >> a >> b;

    int choice;
    cout << "1. Euclidean Algorithm (GCD)\n2. Extended Euclidean Algorithm\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "GCD(" << a << ", " << b << ") = " << gcdEuclid(a, b) << "\n";
            break;
        case 2: {
            int x, y;
            int g = extendedEuclid(a, b, x, y);
            cout << "GCD = " << g << "\n";
            cout << x << " * " << a << " + " << y << " * " << b << " = " << g << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

// ---------- 2. Binary integer add / multiply / divide ----------
string trimZeros(string s) {
    int i = 0;
    while (i < (int)s.size() - 1 && s[i] == '0') i++;
    return s.substr(i);
}

string binaryAdd(string a, string b) {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (char)('0' + sum % 2);
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return trimZeros(result);
}

string binaryMultiply(string a, string b) {
    string result = "0";
    int shift = 0;
    for (int i = b.size() - 1; i >= 0; i--) {
        if (b[i] == '1') {
            string partial = a + string(shift, '0');
            result = binaryAdd(result, partial);
        }
        shift++;
    }
    return trimZeros(result);
}

void binaryDivide(string a, string b, string &quotient, string &remainder) {
    long long dividend = stoll(a, nullptr, 2);
    long long divisor = stoll(b, nullptr, 2);
    if (divisor == 0) { quotient = "ERROR"; remainder = "DIV BY 0"; return; }
    long long q = dividend / divisor;
    long long r = dividend % divisor;
    quotient = q == 0 ? "0" : bitset<32>(q).to_string();
    remainder = r == 0 ? "0" : bitset<32>(r).to_string();
    quotient = trimZeros(quotient);
    remainder = trimZeros(remainder);
}

void binaryArithmetic() {
    string a, b;
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;

    int choice;
    cout << "1. Addition\n2. Multiplication\n3. Division\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << a << " + " << b << " = " << binaryAdd(a, b) << "\n";
            break;
        case 2:
            cout << a << " * " << b << " = " << binaryMultiply(a, b) << "\n";
            break;
        case 3: {
            string q, r;
            binaryDivide(a, b, q, r);
            cout << a << " / " << b << " -> Quotient = " << q << ", Remainder = " << r << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

// ---------- 3. Boolean matrix operations ----------
void inputBoolMatrix(vector<vector<int>> &M, int rows, int cols, const string &name) {
    cout << "Enter elements of matrix " << name << " (" << rows << "x" << cols << ", 0/1):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> M[i][j];
}

void printBoolMatrix(const vector<vector<int>> &M) {
    for (auto &row : M) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

void booleanMatrixOperations() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;
    vector<vector<int>> A(r1, vector<int>(c1));
    inputBoolMatrix(A, r1, c1, "A");

    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;
    vector<vector<int>> B(r2, vector<int>(c2));
    inputBoolMatrix(B, r2, c2, "B");

    int choice;
    cout << "1. Join (A OR B, elementwise)\n2. Meet/Product (A AND B, elementwise)\n3. Boolean Product (matrix multiplication with AND-OR)\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            if (r1 != r2 || c1 != c2) { cout << "Dimensions must match for Join\n"; break; }
            vector<vector<int>> J(r1, vector<int>(c1));
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    J[i][j] = A[i][j] | B[i][j];
            cout << "A JOIN B =\n";
            printBoolMatrix(J);
            break;
        }
        case 2: {
            if (r1 != r2 || c1 != c2) { cout << "Dimensions must match for Meet\n"; break; }
            vector<vector<int>> P(r1, vector<int>(c1));
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    P[i][j] = A[i][j] & B[i][j];
            cout << "A MEET B =\n";
            printBoolMatrix(P);
            break;
        }
        case 3: {
            if (c1 != r2) { cout << "A's columns must equal B's rows for Boolean product\n"; break; }
            vector<vector<int>> C(r1, vector<int>(c2, 0));
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c2; j++)
                    for (int k = 0; k < c1; k++)
                        C[i][j] |= (A[i][k] & B[k][j]);
            cout << "A (o) B (Boolean product) =\n";
            printBoolMatrix(C);
            break;
        }
        default:
            cout << "Invalid choice\n";
    }
}

// ---------- 4. Large integer operations broken into small integers ----------
// Number stored as vector<int> of single digits, least significant digit first
vector<int> toDigits(const string &s) {
    vector<int> d;
    for (int i = s.size() - 1; i >= 0; i--) d.push_back(s[i] - '0');
    return d;
}

string toStringDigits(vector<int> d) {
    while (d.size() > 1 && d.back() == 0) d.pop_back();
    string s;
    for (int i = d.size() - 1; i >= 0; i--) s += (char)('0' + d[i]);
    return s;
}

vector<int> addLarge(vector<int> a, vector<int> b) {
    vector<int> result;
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

vector<int> multiplyLarge(vector<int> a, vector<int> b) {
    vector<int> result(a.size() + b.size(), 0);
    for (size_t i = 0; i < a.size(); i++) {
        int carry = 0;
        for (size_t j = 0; j < b.size() || carry; j++) {
            long long cur = result[i + j] + carry;
            if (j < b.size()) cur += (long long)a[i] * b[j];
            result[i + j] = cur % 10;
            carry = cur / 10;
        }
    }
    return result;
}

void largeIntegerOperations() {
    string a, b;
    cout << "Enter first large integer: ";
    cin >> a;
    cout << "Enter second large integer: ";
    cin >> b;

    vector<int> da = toDigits(a);
    vector<int> db = toDigits(b);

    int choice;
    cout << "1. Addition\n2. Multiplication\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << a << " + " << b << " = " << toStringDigits(addLarge(da, db)) << "\n";
            break;
        case 2:
            cout << a << " * " << b << " = " << toStringDigits(multiplyLarge(da, db)) << "\n";
            break;
        default:
            cout << "Invalid choice\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 2 =====\n";
        cout << "1. Euclidean and Extended Euclidean Algorithms\n";
        cout << "2. Binary Integer Addition, Multiplication, Division\n";
        cout << "3. Boolean Matrix Operations (Join, Meet/Product, Boolean Product)\n";
        cout << "4. Large Integer Operations (digit array based)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: euclideanAlgorithms();      break;
            case 2: binaryArithmetic();         break;
            case 3: booleanMatrixOperations();  break;
            case 4: largeIntegerOperations();   break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
