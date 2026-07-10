#include<bits/stdc++.h>
using namespace std;
bool bfs(int start,vector<vector<int>>&grid,vector<bool>&vis){
    // queue bananaya
    queue<pair<int,int>>q;
    // start node ko visit karna
    vis[start]=true;
    // queue me start node aur uska parent -1 daalna
    q.push({start,-1});
    // queue khali hone tak loop chalana
    while(!q.empty()){
        // queue ke front se node aur parent nikalna
        int node=q.front().first;
        int parent=q.front().second;
        // queue se front nikalna
        q.pop();
        // node ke sabhi adjacent nodes ke liye loop chalana
        for(auto it:grid[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push({it,node});
            }
            // agar adjacent node visited hai aur wo parent nahi hai to cycle detect ho gaya
            else if(it!=parent){
                return true;
            }
        }
    }
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
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(bfs(i,grid,vis)){
                cout<<"cycle detected"<<endl;
                return 0;
            }
        }
    }

}