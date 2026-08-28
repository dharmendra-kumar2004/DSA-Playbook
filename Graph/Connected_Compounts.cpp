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

void dfs(int src,vector<bool>& vis){
    vis[src] = true;
    for(auto nbr : graph[src]){
        if(!vis[nbr]) dfs(nbr,vis);
    }
}
int count_connected_components(){
    vector<bool> vis(v,false);
    int count = 0;
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            count++;
            dfs(i,vis);
        }
    }
    return count;
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
        add_edge(s,d,true);
    }


    display();

    vector<bool> vis(v,false);

    cout << "Number of connected components: " << count_connected_components() << endl;

    return 0;
}
