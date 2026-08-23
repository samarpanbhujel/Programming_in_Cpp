/*
    Assignment 6
    1. Programs for representing relations, testing its properties, and testing equivalence
    2. Programs to represent graphs, finding shortest path, and generating minimum spanning trees
*/
#include <bits/stdc++.h>
using namespace std;

// ---------- 1. Relations ----------
void inputRelationMatrix(vector<vector<int>> &R, int n) {
    cout << "Enter the " << n << "x" << n << " relation matrix (0/1), row by row:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> R[i][j];
}

bool isReflexive(vector<vector<int>> &R, int n) {
    for (int i = 0; i < n; i++)
        if (R[i][i] != 1) return false;
    return true;
}

bool isSymmetric(vector<vector<int>> &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (R[i][j] != R[j][i]) return false;
    return true;
}

bool isAntisymmetric(vector<vector<int>> &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && R[i][j] == 1 && R[j][i] == 1) return false;
    return true;
}

bool isTransitive(vector<vector<int>> &R, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (R[i][j] == 1)
                for (int k = 0; k < n; k++)
                    if (R[j][k] == 1 && R[i][k] != 1) return false;
    return true;
}

void relationsAndProperties() {
    int n;
    cout << "Enter number of elements in the set: ";
    cin >> n;
    vector<vector<int>> R(n, vector<int>(n));
    inputRelationMatrix(R, n);

    int choice;
    cout << "1. Test Reflexive, Symmetric, Antisymmetric, Transitive\n";
    cout << "2. Test if the relation is an Equivalence Relation\n";
    cout << "Enter choice: ";
    cin >> choice;

    bool refl = isReflexive(R, n);
    bool symm = isSymmetric(R, n);
    bool anti = isAntisymmetric(R, n);
    bool trans = isTransitive(R, n);

    switch (choice) {
        case 1:
            cout << "Reflexive:     " << (refl ? "Yes" : "No") << "\n";
            cout << "Symmetric:     " << (symm ? "Yes" : "No") << "\n";
            cout << "Antisymmetric: " << (anti ? "Yes" : "No") << "\n";
            cout << "Transitive:    " << (trans ? "Yes" : "No") << "\n";
            break;
        case 2:
            if (refl && symm && trans)
                cout << "The relation IS an Equivalence Relation\n";
            else
                cout << "The relation is NOT an Equivalence Relation\n";
            break;
        default:
            cout << "Invalid choice\n";
    }
}

// ---------- 2. Graphs: shortest path (Dijkstra) and MST (Prim's) ----------
const int INF = INT_MAX;

void inputGraph(vector<vector<int>> &G, int n) {
    cout << "Enter the " << n << "x" << n << " weighted adjacency matrix\n";
    cout << "(use 0 for no edge between different vertices):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
}

void dijkstraShortestPath(vector<vector<int>> &G, int n, int src) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] != 0 && dist[u] != INF &&
                dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
            }
        }
    }

    cout << "\nVertex\tDistance from Source(" << src << ")\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

void primMST(vector<vector<int>> &G, int n) {
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (G[u][v] != 0 && !inMST[v] && G[u][v] < key[v]) {
                key[v] = G[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nEdge\tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << G[i][parent[i]] << "\n";
        totalWeight += G[i][parent[i]];
    }
    cout << "Total weight of MST = " << totalWeight << "\n";
}

void graphOperations() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n));
    inputGraph(G, n);

    int choice;
    cout << "1. Find Shortest Path from a Source (Dijkstra's Algorithm)\n";
    cout << "2. Generate Minimum Spanning Tree (Prim's Algorithm)\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int src;
            cout << "Enter source vertex (0 to " << n - 1 << "): ";
            cin >> src;
            dijkstraShortestPath(G, n, src);
            break;
        }
        case 2:
            primMST(G, n);
            break;
        default:
            cout << "Invalid choice\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Assignment 6 =====\n";
        cout << "1. Relations: Representation, Properties, Equivalence Testing\n";
        cout << "2. Graphs: Shortest Path (Dijkstra) and MST (Prim's)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: relationsAndProperties(); break;
            case 2: graphOperations();        break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
