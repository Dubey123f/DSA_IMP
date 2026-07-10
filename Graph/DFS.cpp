#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis){
    //start node visit karo
    vis[node]=1;
    //Node print karo
    cout<<node<<" ";
    // Neighbour node iterate karo
    for(auto it:adj[node]){
        //Agar Neighbour node visit nahi hua hai to usko visit karo
        if(vis[it]==0){
            dfs(it,adj,vis);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"DFS Traversal: "<<endl;
    vector<int>vis(n,0);
    dfs(0,adj,vis);

}