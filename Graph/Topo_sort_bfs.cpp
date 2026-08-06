#include <bits/stdc++.h>
using namespace std;

vector<int> topo_sort; // ans Array
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
void bfs(){
    vector<int>indegree(v,0);
    for(int i = 0; i<v;i++){
        for(int nbr : graph[i]){
            indegree[nbr]++;
        }
    }
    queue<int>qu;
    for(int i = 0; i<v;i++){
        if(indegree[i] == 0){
            qu.push(i);
        }
    }

    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(int nbr : graph[curr]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                qu.push(nbr);
            }
        }
        topo_sort.push_back(curr);
    }
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
    display();// Display the graph

    bfs(); // call bfs function to perform topological sort

    cout << "Topological Sort: ";
    for(int i = 0; i<topo_sort.size(); i++){
        cout << topo_sort[i] << " ";
    }
    cout << endl;

    return 0;
}
