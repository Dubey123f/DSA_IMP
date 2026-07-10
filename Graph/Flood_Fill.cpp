#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<int>> &grid,int oc,int nc){
    //Base case: Agar i aur j grid ke boundary se bahar hai ya grid[i][j] oc nahi hai to return karo
    if(i<0 || j<0 ||i>=grid.size()||j>=grid[0].size()){
        return;
    }
    //Agar current cell me oc nahi hai to return karo
     if(grid[i][j] != oc){
        return;
    }
    //Mark the current cell with nc
    grid[i][j]=nc;
    //4 direction me DFS call karo
    dfs(i+1,j,grid,oc,nc);dfs(i-1,j,grid,oc,nc);
    dfs(i,j+1,grid,oc,nc);dfs(i,j-1,grid,oc,nc);
}
int main(){
    int n,m;
    cin>>n>>m;
     int nc;
     cin>>nc;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int oc=grid[0][0];
   
    dfs(0,0,grid,oc,nc);
    cout<<"Flood Fill Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

}