#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
// node ko visit karo
vis[node]=1;
// Node ke neighbours ko iterate karo, agar neighbour node visit nahi hua hai to usko visit karo
for(int j=0;j<adj[node].size();j++){
    // Agar neighbour node ke saath connection hai aur neighbour node visit nahi hua hai to usko visit karo
    if(adj[node][j]==1 && !vis[j]){
        dfs(j,adj,vis);
    }
}
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    // Create a visited array to keep track of visited nodes
    vector<int>vis(n,0);
    // Count the number of provinces by counting the number of times we need to call DFS to visit all the nodes
    int count=0;
    // Iterate through all the nodes, agar node visit nahi hua hai to usko visit karo aur count ko 1 se badha do
    for(int i=0;i<n;i++){
        // Agar node visit nahi hua hai to usko visit karo aur count ko 1 se badha do
        if(!vis[i]){
            count++;
            dfs(i,adj,vis);
        }
    }
    cout<<"Number of Provinces: "<<count<<endl;

}