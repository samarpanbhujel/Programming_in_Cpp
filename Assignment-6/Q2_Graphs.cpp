// Programs to represent graphs, finding shortest path, and generating minimum spanning trees.
#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\nGraph Representation:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}