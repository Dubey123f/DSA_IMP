#include<bits/stdc++.h>
using namespace std;
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
    //color array banaya jisme -1 se initialize kiya hai
    vector<int>color(n,-1);
    // ab iterate karna hai graph par
    for(int i=0;i<n;i++){
        //agar color[i] -1 hai to usko color karna hai
        if(color[i]==-1){
            // queue bananaya
            queue<int>q;
            // queue me node daalna
            q.push(i);
            // node ko color karna
            color[i]=0;
            // queue khali hone tak loop chalana
            while(!q.empty()){
                // queue ke front se node nikalna
                int node=q.front();
                // queue se front nikalna
                q.pop();
                //neighbor pe iterate karenge
                for(auto it:grid[node]){
                    //agar neighbor ka color -1 hai to usko color karna hai
                    if(color[it]==-1){
                        //neighbor ka color opposite hoga node ke color ka
                        color[it]=1-color[node];
                        //neighbor ko queue me daalna
                        q.push(it);
                    }
                    //agar neighbor ka color node ke color ke barabar hai to graph bipartite nahi hai
                    else if(color[it]==color[node]){
                        cout<<"not bipartite"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"bipartite"<<endl;
}