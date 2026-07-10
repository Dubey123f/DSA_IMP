#include<bits/stdc++.h>
using namespace std;
bool cycle(int node,vector<vector<int>>&grid){
    // ek array bana indegree ke liye
    vector<int>indegree(grid.size(),0);
    // iterate karo grid par
    for(int i=0;i<grid.size();i++){
        // iterate karo grid ke adjacent nodes par
        for(auto it:grid[i]){
            // adjacent node ke indegree ko 1 se badhao
            indegree[it]++;
        }
    }
    // queue bananaya
    queue<int>q;
    // indegree 0 wale nodes ko queue me daalna
    for(int i=0;i<grid.size();i++){
        // indegree 0 wale nodes ko queue me daalna
        if(indegree[i]==0){
            q.push(i);
        }

    }
    // queue khali hone tak loop chalana
    int c=0;
    // queue khali hone tak loop chalana
    while(!q.empty()){
        // queue ke front se node nikalna
        int node=q.front();
        // queue se front nikalna
        q.pop();
        //count badhao
        c++;
        // grid ke adjacent par iterarte kro
        for(auto it:grid[node]){
            // uska indegree decrease karo
            indegree[it]--;
            // if indegree 0 hua to q me push karo
            if(indegree[it]==0){
                q.push(it);
            }
            
        }
    }
    // agar count grid ke size ke barabar nahi hai to cycle detect ho gaya
    return c!=grid.size();
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        grid[u].push_back(v);
    }
    if(cycle(0,grid)){
        cout<<"cycle detected"<<endl;
    }
    else{
        cout<<"cycle not detected"<<endl;
    }

}