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
    void union_set(int u , int v){
           int pu=find(u);
           int pv=find(v);
           if(pu==pv){
            return;
           }
           if(rank[pv]<rank[pu]){
            parent[pv]=pu;
           }
           else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
           }
           else{
            parent[pv]=pu;
            rank[pu]++;
           }
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n+1);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            if(d.find(u)==d.find(v)){
                return e;
            }
            d.union_set(u,v);
        }
        return {};
    }
};