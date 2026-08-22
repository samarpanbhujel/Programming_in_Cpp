// Programs for representing relations, testing their properties, and testing equivalence.
#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int relation[10][10];

    cout << "Enter the relation matrix (0 or 1):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> relation[i][j];
        }
    }

    // Display relation
    cout << "\nRelation Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << relation[i][j] << " ";
        }
        cout << endl;
    }

    // Reflexive
    bool reflexive = true;

    for (int i = 0; i < n; i++) {
        if (relation[i][i] != 1) {
            reflexive = false;
            break;
        }
    }

    // Symmetric
    bool symmetric = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (relation[i][j] != relation[j][i]) {
                symmetric = false;
                break;
            }
        }
    }

    // Antisymmetric
    bool antisymmetric = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i != j &&
                relation[i][j] == 1 &&
                relation[j][i] == 1) {

                antisymmetric = false;
                break;
            }
        }
    }

    // Transitive
    bool transitive = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

                if (relation[i][j] == 1 &&
                    relation[j][k] == 1 &&
                    relation[i][k] == 0) {

                    transitive = false;
                    break;
                }
            }
        }
    }

    // Results
    cout << "\nProperties of Relation:\n";

    if (reflexive)
        cout << "Reflexive: Yes\n";
    else
        cout << "Reflexive: No\n";

    if (symmetric)
        cout << "Symmetric: Yes\n";
    else
        cout << "Symmetric: No\n";

    if (antisymmetric)
        cout << "Antisymmetric: Yes\n";
    else
        cout << "Antisymmetric: No\n";

    if (transitive)
        cout << "Transitive: Yes\n";
    else
        cout << "Transitive: No\n";

    // Equivalence
    if (reflexive && symmetric && transitive)
        cout << "Equivalence Relation: Yes\n";
    else
        cout << "Equivalence Relation: No\n";

    return 0;
}