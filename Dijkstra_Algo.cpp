#include <bits/stdc++.h>
using namespace std;
#define p pair<int,int>   // p means a pair of (int, int) → used for (distance, node)

int v;   // number of vertices
vector<vector<p>> graph;   // adjacency list representation of graph

// Dijkstra algorithm function
void dijkstra(int src, vector<int>& dist) {
    // priority queue to store (distance, node), smallest distance comes first
    priority_queue<p, vector<p>, greater<p>> pq;
    dist[src] = 0;          // distance of source node is 0
    pq.push({0, src});      // push source node with distance 0

    while(!pq.empty()) {
        int u = pq.top().second;   // get node with smallest distance
        pq.pop();

        // check all neighbours of node u
        for(auto it : graph[u]) {
            int v = it.first;      // neighbour node
            int w = it.second;     // edge weight
            int totaldist = dist[u] + w;   // new possible distance

            // if new distance is smaller, update it
            if(totaldist < dist[v]) {
                dist[v] = totaldist;
                pq.push({dist[v], v});   // push updated distance and node
            }
        }
    }
}

// function to add edge in graph
void add_edge(int src, int dest, int cost, bool bi_dir) {
    graph[src].push_back({dest, cost});   // add edge src → dest
    if(bi_dir) {
        graph[dest].push_back({src, cost});   // if bidirectional, also add dest → src
    }
}

int main() {
    cout << "No of vertexes : ";
    cin >> v;
    graph.resize(v+1);   // resize graph to hold v nodes (1-based indexing)

    int e;
    cout << "No of Edges : ";
    cin >> e;
    while(e--) {
        int s, d, w;
        cin >> s >> d >> w;   // read edge (source, destination, weight)
        add_edge(s, d, w, true);
    }

    // initialize all distances as infinity
    vector<int> dist(v, INT_MAX);
    int src;
    cout << "Enter the src : ";
    cin >> src;
    // run Dijkstra from source node 0
    dijkstra(src, dist);

    cout << "Shortest distances from source "<< src << " : ";
    for(int i = 0; i < v; i++) {
        if(dist[i] == INT_MAX) cout << "INF ";   // if node not reachable
        else cout << dist[i] << " ";             // print shortest distance
    }
    cout << endl;

    return 0;
}
