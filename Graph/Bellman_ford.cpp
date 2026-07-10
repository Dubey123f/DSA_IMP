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
    //distance array banauga
    vector<int>dist(n,INT_MAX);
    //
    int src=0;
    //source node se distance 0 karou
    dist[src]=0;
    //K times relax karou
 for(int k=0;k<n-1;k++){
       //har edge ke liye relax karou
        for(int i=0;i<n;i++){
            //har edge ke liye relax karou
            for(auto it:grid[i]){
                //agar distance i se it.first se kam hai to update karou
                if(dist[i]!=INT_MAX && dist[i]+it.second < dist[it.first]){
                    dist[it.first]=dist[i]+it.second;
                }
            }
        }
    }
    //negative cycle detect karou
    for(int i=0;i<n;i++){
        //har edge ke liye relax karou
        for(auto it:grid[i]){
            //agar distance i se it.first se kam hai to negative cycle detect karou
            if(dist[i]!=INT_MAX && dist[i]+it.second<dist[it.first]){
                cout<<"negative cycle detected"<<endl;
                return 0;
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