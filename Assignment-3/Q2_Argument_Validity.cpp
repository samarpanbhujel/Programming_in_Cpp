// Programs to test validity of arguments by using truth tables.
#include <iostream>
using namespace std;

int main() {

    bool valid = true;

    cout << "P Q | P -> Q | P | Q" << endl;
    cout << "------------------------" << endl;

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {

            bool premise1 = (!P) || Q;
            bool premise2 = P;
            bool conclusion = Q;

            cout << P << " " << Q << " |   "
                 << premise1 << "    | "
                 << premise2 << " | "
                 << conclusion << endl;

            // If all premises are true but conclusion is false,
            // the argument is invalid.
            if (premise1 && premise2 && !conclusion) {
                valid = false;
            }
        }
    }

    cout << endl;

    if (valid)
        cout << "The argument is VALID." << endl;
    else
        cout << "The argument is INVALID." << endl;

    return 0;
}