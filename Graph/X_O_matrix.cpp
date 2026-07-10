#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&grid){
    //Base case: Agar i aur j grid ke boundary se bahar hai ya grid[i][j] 'O' nahi hai to return karo
    if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size()||grid[i][j] != 'O'){
        return;
    }
    //Mark the current cell as 'S' to indicate that it is safe and cannot be converted to 'X'
   
    grid[i][j]='S';
    //4 direction me DFS call karo
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    // Boundary cells se DFS call karo aur unko 'S' mark karo, taki unko 'X' me convert na kiya jaye
    // First and last row ke cells ke liye DFS call karo
  for(int j=0;j<m;j++){
    
        dfs(0,j,grid);
  
   
        dfs(n-1,j,grid);
    
  }
  // First and last column ke cells ke liye DFS call karo
  for(int i=0;i<n;i++){
   
        dfs(i,0,grid);
    
   
        dfs(i,m-1,grid);
    

  }
  // Ab grid ke andar ke cells ko iterate karo, agar cell 'O' hai to usko 'X' me convert karo, aur agar cell 'S' hai to usko 'O' me convert karo
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='O'){
            grid[i][j]='X';
        }
        else if(grid[i][j]=='S'){
            grid[i][j]='O';
        }
    }
  }
  cout<<"X O Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }


}

