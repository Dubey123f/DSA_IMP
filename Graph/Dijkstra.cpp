#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int start,vector<vector<pair<int,int>>>&grid){
    vector<int>dist(grid.size(),INT_MAX);
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int u=node.first;
        int v=node.second;
        if(dist[v]<u){
            continue;
        }
        for(auto it:grid[v]){
            int a=it.first;
            int b=it.second;
            if(dist[v]+b<dist[a]){
                dist[a]=dist[v]+b;
                pq.push({dist[a],a});
            }
        }
    }
    return dist;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>grid(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        grid[u].push_back({v,w});
        grid[v].push_back({u,w});
    }
    int start;
    cin>>start;
    vector<int>dist=dijkstra(start,grid);
    for(int i=0;i<dist.size();i++){
        cout<<"Distance from "<<start<<" to "<<i<<" is "<<dist[i]<<endl;
    }
    

}