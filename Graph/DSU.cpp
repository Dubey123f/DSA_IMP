#include<bits/stdc++.h>
using namespace std;
class DSU{
    //Parent and rank arrays
    vector<int>parent;
    vector<int>rank;
    public:
    //Constructor to initialize the parent and rank arrays
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        //Initially, each element is its own parent and has rank 0
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    // Find function banaunga
    int find(int u){
        //path compare karou ki parent ke equal hai ya nahi
        if(parent[u]==u){
            return u;
        }
        //path compression technique use karou
        return parent[u]=find(parent[u]);
    }
    //Union function banaunga
    void union_set(int u,int v){
        //Find the parent of u and v
        int pu=find(u);
        int pv=find(v);
        //agar dono ke parent same hai to return karou
        if(pu==pv){
            return;
        }
        //Union by rank technique use karou
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
    DSU dsu(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dsu.union_set(u,v);
    }
set<int>st;
    for(int i=1;i<=n;i++){
        st.insert(dsu.find(i));
    }

    cout<<st.size()<<endl;

}