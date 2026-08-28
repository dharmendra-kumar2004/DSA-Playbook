#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent, Rank;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (Rank[a] > Rank[b]) {
        parent[b] = a;
    }
    else if (Rank[a] < Rank[b]) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
        Rank[a]++;
    }
}

int main() {

    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    // 0-based indexing: vertices 0 to v-1
    parent.resize(v);
    Rank.resize(v, 0);
    graph.resize(v);

    // Initially every vertex is its own parent
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    while (e--) {
        int u, w;

        cout << "Enter edge (u v): ";
        cin >> u >> w;

        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    // Union all connected vertices
    for (int i = 0; i < v; i++) {
        for (int j : graph[i]) {
            union_set(i, j);
        }
    }

    // Count roots
    int countConnectedComponents = 0;

    for (int i = 0; i < v; i++) {
        if (find(i) == i) {
            countConnectedComponents++;
        }
    }

    cout << "Number of connected components: "
         << countConnectedComponents << endl;

    return 0;
}