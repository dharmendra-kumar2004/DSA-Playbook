#include <bits/stdc++.h>
using namespace std;
vector<int> topo_sort;
vector<vector<int>> graph;
int v;

void add_edge(int src,int dest,bool bi_dir){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(auto x : graph[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}
void dfs(int src,vector<bool> &visited){
    visited[src] = true;
    
    for(int nbr : graph[src]){
        if(!visited[nbr]){
            dfs(nbr,visited);
        }
    }
    topo_sort.push_back(src);

}

int main(){
    cout << "No of vertexes : ";
    cin >> v;
    graph.resize(v, vector<int>());

    int e;
    cout << "No of Edges : ";
    cin >> e;
    while(e--){
        int s,d;
        cin >> s >> d;
        add_edge(s,d,false);
    }


    display();

    vector<bool> visited(v, false);
    for(int i = 0; i<v; i++){
        if(!visited[i]) dfs(i, visited);
    }
    
    cout << "Topological Sort: ";
    for(int i = topo_sort.size()-1; i>=0; i--){
        cout << topo_sort[i] << " ";
    }
    cout << endl;

    return 0;
}
