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
        else if(rank[pu]>rank[pv]){
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU d(n+1);
        vector<pair<int,pair<int,int>>>edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[j][0];
            int y2=points[j][1];
            int dist=(abs(x1-x2)+abs(y1-y2));
            edges.push_back({dist,{i,j}});

        }
        }
        sort(edges.begin(),edges.end());
        int c=0;
        for(auto e:edges){
            int w=e.first;
            int u=e.second.first;
            int v=e.second.second;
            if(d.find(u)!=d.find(v)){
               c+=w;
               d.union_set(u,v);
            }

        }
        return c;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>>points(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }
    Solution s;
    cout<<s.minCostConnectPoints(points)<<endl;
}