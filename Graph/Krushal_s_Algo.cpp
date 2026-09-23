#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define tp tuple<int, int, int>

int v;

vector<vector<p>> graph;
vector<int> parent;

// Find leader
int leader(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = leader(parent[x]);
}

// Union
void union_set(int a, int b) {

    a = leader(a);
    b = leader(b);

    if (a != b)
        parent[b] = a;
}

// Kruskal's Algorithm
void kruskal_algo(
    vector<vector<int>>& mst,
    priority_queue<tp, vector<tp>, greater<tp>> pq
) {

    while (!pq.empty() && mst.size() < v - 1) {

        tp curr = pq.top();
        pq.pop();

        int w = get<0>(curr);
        int u = get<1>(curr);
        int node = get<2>(curr);

        // If they belong to different components
        if (leader(u) != leader(node)) {

            mst.push_back({u, node, w});

            union_set(u, node);
        }
    }
}

// Add edge
void add_edge(int src, int dest, int cost, bool bi_dir) {

    graph[src].push_back({dest, cost});

    if (bi_dir) {
        graph[dest].push_back({src, cost});
    }
}

int main() {

    cout << "No of vertexes : ";
    cin >> v;

    graph.resize(v);
    parent.resize(v);

    // Initially every vertex is its own parent
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    int e;

    cout << "No of Edges : ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";

    while (e--) {

        int s, d, w;
        cin >> s >> d >> w;

        add_edge(s, d, w, true);
    }

    vector<vector<int>> mst;

    // Priority queue containing ALL edges
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    for (int u = 0; u < v; u++) {

        for (auto it : graph[u]) {

            int node = it.first;
            int weight = it.second;

            // Because graph is undirected,
            // each edge appears twice.
            if (u < node) {
                pq.push({weight, u, node});
            }
        }
    }

    // Run Kruskal
    kruskal_algo(mst, pq);

    // Create MST adjacency list
    vector<vector<p>> mstGraph(v);

    int totalWeight = 0;

    for (vector<int> edge : mst) {

        int u = edge[0];
        int node = edge[1];
        int w = edge[2];

        mstGraph[u].push_back({node, w});
        mstGraph[node].push_back({u, w});

        totalWeight += w;
    }

    // Print MST
    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < v; i++) {

        cout << i << " -> ";

        for (p it : mstGraph[i]) {

            cout << "("
                 << it.first << ","
                 << it.second << ") ";
        }

        cout << endl;
    }

    cout << "\nTotal Weight = "
         << totalWeight << endl;

    return 0;
}