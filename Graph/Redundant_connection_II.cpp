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
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n+1);
        vector<int>p(n+1,0);
        vector<int>e1,e2;

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            if(p[v]==0){
                p[v]=u;
            }
            else{
                e1={p[v],v};
                e2={u,v};
                 e[1]=0;
            }

        }
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            if(v==0){
                continue;
            }
            if(d.find(u)==d.find(v)){
                if(e1.empty()){
                    return e;
                }
                return e1;
            }
            d.union_set(u,v);
        }
        return e2;
    
    }
};