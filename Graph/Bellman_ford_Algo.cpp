#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;   // adjacency list representation of graph
int v;   // number of vertices

// Bellman-Ford algorithm function
void bellman_ford(int src,vector<int>& dist){
    dist[src] = 0;  // distance of source node is 0

    for(int i = 1; i<v; i++){
        for(int u = 0; u<v; u++){
            for(auto it : graph[u]){
                int to = it.first;      // destination
                int w = it.second;     // edge weight

                if(dist[u] != INT_MAX && dist[u] + w < dist[to]){
                    dist[to] = dist[u] + w;   // update distance if a shorter path is found
                }
            }
        }
    }
}

int main(){
    cout << "No of vertexes :";
    cin >> v;
    graph.resize(v);
    int e;
    cout << "No of Edges :";
    cin >> e;
    while(e--){
        int s,d,w;
        cin >> s >> d >> w;   // read edge (source, destination, weight)
        graph[s].push_back({d,w});   // add edge to adjacency list  
    }
    vector<int> dist(v,INT_MAX);
    int src;
    cout << "Enter the src :";
    cin >> src;
    bellman_ford(src, dist);
    for(int i = 0; i<v; i++){
        if(dist[i] == INT_MAX){
            cout <<"INF" << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    return 0;
}