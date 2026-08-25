#include<bits/stdc++.h>
using namespace std;

// Bellman-Ford algorithm with negative cycle detection
vector<vector<int>> edges;  // list of edges (source, destination, weight)
int V; // numbers of vertices

void bellman_ford(int src,vector<int>& dist, bool& hasNegativeCycle){
    dist[src] = 0;
    for(int i = 1; i<V; i++){
        for(auto edge : edges ){
            int u = edge[0];
            int v = edge[1];;
            int w = edge[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            } 
        }
    }
    int maxDist = 0;
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Negative cycle detected!" << endl;
            hasNegativeCycle = true;
            return;
        }
        maxDist = max(maxDist, dist[u] + w);
    }   
}
int main(){
    cout << "No of vertexes :";
    cin >> V;
    int E;
    cout << "No of Edges :";
    cin >> E;
    edges.resize(E);
    for(int i = 0; i<E; i++){
        int s,d,w;
        cin >> s >> d >> w;   // read edge (source, destination, weight)
        edges[i] = {s,d,w};   // add edge to edge list
    }
    vector<int> dist(V,INT_MAX);
    int src;
    cout << "Enter the src :";
    cin >> src;
    bool hasNegativeCycle = false;
    bellman_ford(src, dist, hasNegativeCycle);
    if(!hasNegativeCycle){
        for(int i = 0; i<V; i++){
            if(dist[i] == INT_MAX){
                cout <<"INF" << " ";
            } else {
                cout << dist[i] << " ";
            }
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}