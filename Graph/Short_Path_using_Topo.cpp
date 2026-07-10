#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>grid(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        grid[u].push_back({v,w});
    }
    vector<int>indegree(n,0);
   
    for(int i=0;i<n;i++){
        for(auto it:grid[i]){
            indegree[it.first]++;
        }
    }
     queue<int>q;
     for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }
     vector<int>topo;
     while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:grid[node]){
            indegree[it.first]--;
            if(indegree[it.first]==0){
                q.push(it.first);
            }
        }
       
     }

     vector<int>dist(n,INT_MAX);
        dist[0]=0;
        for(int i=0;i<topo.size();i++){
            int node=topo[i];
            for(auto it:grid[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }

            }

        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i]<<" ";
            }
        }
}