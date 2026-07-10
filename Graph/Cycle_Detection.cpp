#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>&grid,vector<int>&vis,vector<int>&pathVis){
    // node ko visit karna
    vis[node]=1;
    // node ko pathVis me daalna
    pathVis[node]=1;
    // node ke sabhi adjacent nodes ke liye loop chalana
    for(auto it:grid[node]){
        // agar adjacent node visited nahi hai to usko visit karna
        if(vis[it]==0){
            // agar adjacent node visited nahi hai to usko visit karna
            if(dfs(it,grid,vis,pathVis)){
                return true;
            }
        }
        // agar adjacent node visited hai aur wo pathVis me hai to cycle detect ho gaya
        else if(pathVis[it]==1){
            return true;
        }
       
    }
    // node ko pathVis se nikalna
     pathVis[node]=0;
        return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(dfs(i,grid,vis,pathVis)){
                cout<<"cycle detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"cycle not detected"<<endl;

}