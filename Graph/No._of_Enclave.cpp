#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<int>>&grid){
    //Base case: Agar i aur j grid ke boundary se bahar hai ya grid[i][j] 0 nahi hai to return karo
    if(i<0 ||j<0 || i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
        return;
    }
    //Mark the current cell as 3 to indicate that it is visited and cannot be counted as an enclave
    grid[i][j]=3;
    //4 direction me DFS call karo
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    // Boundary cells se DFS call karo taki unko 3 mark kiya jaye aur unko enclave me count na kiya jaye
   for(int i=0;i<n;i++){
    dfs(i,0,grid);
    dfs(i,m-1,grid);
   } 
   // First and last row ke cells ke liye DFS call karo
   for(int j=0;j<m;j++){
    dfs(0,j,grid);
    dfs(n-1,j,grid);
   } 
   // Ab grid ke andar ke cells ko iterate karo, agar cell me 1 hai to usko count karo, aur agar cell me 3 hai to usko 1 me convert kar do taki baad me usko count kiya ja sake
   int count=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==1){
            count++;
        }
        if(grid[i][j]==3){
            grid[i][j]=1;
        }
    }
   }
    cout<<"Number of Enclaves: "<<count<<endl;

}