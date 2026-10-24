#include<bits/stdc++.h>
using namespace std;

int ans;

bool CanWeGo(int n,int i,int j, vector<vector<int>> &grid){
    return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0;
}

void RatInAMaze(vector<vector<int>> &grid,int n,int i,int j){
    if(i == n-1 && j == n-1){
        ans++;
        return;
    }

    grid[i][j] = 2; // 2 mean visited

    //left
    if(CanWeGo(n,i,j-1,grid)){
        RatInAMaze(grid,n,i,j-1);
    }
    //right
    if(CanWeGo(n,i,j+1,grid)){
        RatInAMaze(grid,n,i,j+1);
    }
    //up
    if(CanWeGo(n,i-1,j,grid)){
        RatInAMaze(grid,n,i-1,j);
    }
    //down
    if(CanWeGo(n,i+1,j,grid)){
        RatInAMaze(grid,n,i+1,j);
    }
    grid[i][j] = 0; // backtrack
}
int main(){
    int n;
    cout << "Enter the size of the grid : ";
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    ans = 0;
    RatInAMaze(grid,n,0,0);
    cout << "Number of paths from top-left to bottom-right : " << ans << endl;

    return 0;
}