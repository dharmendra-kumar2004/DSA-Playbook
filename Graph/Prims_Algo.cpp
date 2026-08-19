#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define tp tuple<int, int, int>

int v;
vector<vector<p> > graph;

// Prim's Algorithm
void prims_algo(int src, vector<bool>& vis, vector<vector<int> >& mst) {

    // (weight, node, parent)
    priority_queue<tp, vector<tp>, greater<tp> > pq;

    pq.push(make_tuple(0, src, -1));

    while (!pq.empty()) {

        tp current = pq.top();
        pq.pop();

        int w = get<0>(current);
        int u = get<1>(current);
        int parent = get<2>(current);

        // Already visited node
        if (vis[u]) continue;

        // Mark node visited
        vis[u] = true;

        // Source ka parent -1 hai, isliye source ki edge MST mein nahi jayegi
        if (parent != -1) {
            mst.push_back(vector<int>{parent, u, w});
        }

        // Neighbours check karo
        for (auto it : graph[u]) {

            int neighbour = it.first;
            int weight = it.second;

            if (!vis[neighbour]) {
                pq.push(make_tuple(weight, neighbour, u));
            }
        }
    }
}

// Add edge
void add_edge(int src, int dest, int cost, bool bi_dir) {

    graph[src].push_back(make_pair(dest, cost));

    if (bi_dir) {
        graph[dest].push_back(make_pair(src, cost));
    }
}

int main() {

    cout << "No of vertexes : ";
    cin >> v;

    // 0-based indexing: 0, 1, 2, ..., v-1
    graph.resize(v);

    int e;
    cout << "No of Edges : ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";

    while (e--) {

        int s, d, w;
        cin >> s >> d >> w;

        add_edge(s, d, w, true);
    }

    vector<bool> vis(v, false);

    vector<vector<int> > mst;

    int src;
    cout << "Enter the src : ";
    cin >> src;

    // Run Prim's Algorithm
    prims_algo(src, vis, mst);

    // Create MST adjacency list
    vector<vector<p> > mstGraph(v);

    int totalWeight = 0;

    for (auto edge : mst) {

        int u = edge[0];
        int node = edge[1];
        int w = edge[2];

        // MST is undirected
        mstGraph[u].push_back(make_pair(node, w));
        mstGraph[node].push_back(make_pair(u, w));

        // Add weight only once
        totalWeight += w;
    }

    // Print MST in required format
    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < v; i++) {

        cout << i << " -> ";

        for (auto it : mstGraph[i]) {
            cout << "("<< it.first << ","<< it.second<< ") ";
        }
        cout << endl;
    }

    // Print total weight
    cout << "\nTotal Weight = " << totalWeight << endl;

    return 0;
}