#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v;
vector<int> ans;

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
    ans.push_back(src);
    for(auto nbr : graph[src]){
        if(!vis[nbr]) dfs(nbr,vis);
    }
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
    cout << "Enter source for DFS: ";
    cin >> src;
    vector<bool> vis(v,false);
    dfs(src,vis);

    for(int i = 0; i<v; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
