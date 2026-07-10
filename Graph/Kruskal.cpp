#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void union_set(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }

    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    DSU d(n+1);
    int cost=0;
    for(auto edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(d.find(u)==d.find(v)){
            continue;
        }
        if(d.find(u)!=d.find(v)){
            cost+=w;
            d.union_set(u,v);
        }
    }
    cout<<cost<<endl;

}