#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid;
     for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        grid.push_back({a, b});
    }
    int numCourses;
    cin>>numCourses;
    vector<vector<int>>adj(numCourses);
    vector<int>indegree(numCourses,0);

    for(auto it:grid){
        int x=it[0];
        int y=it[1];
        adj[y].push_back(x);
        indegree[x]++;
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int c=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        c++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }

    }
    if(c==numCourses){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"not possible"<<endl;
    }

}