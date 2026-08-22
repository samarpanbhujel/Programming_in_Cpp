// Programs to generate truth tables of compound propositions.
#include <iostream>
using namespace std;

int main() {

    cout << "P Q | P AND Q | P OR Q | (P AND Q) -> (P OR Q)" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {

            int andResult = P && Q;
            int orResult = P || Q;

            // P -> Q is false only when P = 1 and Q = 0
            int implication = (!andResult) || orResult;

            cout << P << " " << Q << " |    "
                 << andResult << "     |    "
                 << orResult << "    |          "
                 << implication << endl;
        }
    }

    return 0;
}