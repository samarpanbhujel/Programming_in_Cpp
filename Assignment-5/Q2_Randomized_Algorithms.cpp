// Programs to implement some probabilistic and randomized algorithms.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int n;
    int inside = 0;

    cout << "Enter number of random points: ";
    cin >> n;

    // Seed random number generator
    srand(time(0));

    for (int i = 0; i < n; i++) {

        // Generate random x and y between -1 and 1
        double x = (double)rand() / RAND_MAX * 2 - 1;
        double y = (double)rand() / RAND_MAX * 2 - 1;

        // Check whether point is inside circle
        if (x * x + y * y <= 1)
            inside++;
    }

    double pi = 4.0 * inside / n;

    cout << "Estimated value of PI = "
         << pi << endl;

    return 0;
}