#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&grid){
    //Boundry Condition Check
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
        return;
    }
    // agar current cell wather the return
    if(grid[i][j]=='0'){
        return;
    }
    // mark the current cell as visited
    grid[i][j]='0';
    // call dfs for all the 4 directions
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //Create variable to count the number of islands
    int count=0;
    //Iterate through the grid and call dfs for every unvisited land cell
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // If the current cell is land then call dfs and increment the count
            if(grid[i][j]=='1'){
                count++;
                dfs(i,j,grid);
            }
        }
    }
    // Print the number of islands
    cout<<count<<endl;
}