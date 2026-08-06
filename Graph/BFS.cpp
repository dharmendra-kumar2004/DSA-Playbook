#include <bits/stdc++.h>
using namespace std;

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

void bfs(int src){
    vector<bool> visited(v+1, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    cout << "BFS starting from " << src << " : ";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neigh : graph[node]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

int main(){
    cout << "No of vertexes : ";
    cin >> v;
    graph.resize(v+1, vector<int>());

    int e;
    cout << "No of Edges : ";
    cin >> e;
    while(e--){
        int s,d;
        cin >> s >> d;
        add_edge(s,d,true);
    }


    display();

    int src;
    cout << "Enter source for BFS: ";
    cin >> src;
    bfs(src);

    return 0;
}
