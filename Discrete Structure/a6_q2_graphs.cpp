/*
 * Assignment 6 - Question 2
 * Program to represent a weighted graph using an adjacency matrix,
 * find the shortest path from a source vertex (Dijkstra's algorithm),
 * and generate a minimum spanning tree (Prim's algorithm).
 * Use 0 to represent "no edge" between two distinct vertices.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<vector<int>> Graph;

Graph readGraph(int n) {
    Graph g(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n
         << " adjacency matrix (weights; use 0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    return g;
}

void printGraph(const Graph &g) {
    for (const auto &row : g) {
        for (int w : row) cout << w << " ";
        cout << endl;
    }
}

void dijkstra(const Graph &g, int n, int src) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, minDist = INT_MAX;
        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[v] <= minDist) { minDist = dist[v]; u = v; }
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && g[u][v] != 0 && dist[u] != INT_MAX &&
                dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";
        if (dist[i] == INT_MAX) cout << "unreachable\n";
        else cout << dist[i] << endl;
    }
}

void primsMST(const Graph &g, int n) {
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, minKey = INT_MAX;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && key[v] < minKey) { minKey = key[v]; u = v; }
        if (u == -1) break;
        inMST[u] = true;

        for (int v = 0; v < n; v++)
            if (g[u][v] != 0 && !inMST[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    cout << "Minimum Spanning Tree edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "  (weight " << g[i][parent[i]] << ")\n";
            totalWeight += g[i][parent[i]];
        }
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g = readGraph(n);

    int choice;
    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Display graph (adjacency matrix)\n";
        cout << "2. Find shortest path from a source (Dijkstra's algorithm)\n";
        cout << "3. Generate Minimum Spanning Tree (Prim's algorithm)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printGraph(g);
                break;
            case 2: {
                int src;
                cout << "Enter source vertex (0.." << n - 1 << "): ";
                cin >> src;
                dijkstra(g, n, src);
                break;
            }
            case 3:
                primsMST(g, n);
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
