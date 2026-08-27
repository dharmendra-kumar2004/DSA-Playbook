#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj; // adjacency list (destination, weight)
int V; // number of vertices

void floyd_worshall(vector<vector<int>>& dist){
    for(int k = 0; k<V;k++){
        for(int i = 0;i<V; i++){
            if(i == k) continue; // skip if source and intermediate are the same
            for(int j = 0; j<V; j++){
                if(j == k || j == i) continue; // skip if destination and intermediate are the same or source and destination are the same
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    cout << "NO of vertexes : ";
    cin >> V;
    int E;
    cout << "No of edges : ";
    cin >> E;
    adj.resize(V);
    while(E--){
        int u,v,w;
        cin >> u >> v >> w; // read edge (source, destination, weight)
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // for undirected graph
    }

    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i = 0; i<V; i++){
        dist[i][i] = 0; // distance from a vertex to itself is 0
        for(auto edge : adj[i]){
            int v = edge.first;
            int w = edge.second;
            dist[i][v] = w; // initialize distance with edge weights
        }
    }
    floyd_worshall(dist);
    cout << "Shortest distances between every pair of vertices:" << endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(dist[i][j] == INT_MAX){
                cout << "INF" << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}