#include<bits/stdc++.h>
using namespace std;
void bfs(int start,vector<int>adj[],int n){
    //Created this array to check weather a node is visited or not
    vector<int>vis(n,0);
    // Create this queue to store the nodes which are to be visited
    queue<int>q;
    // Push the starting node in the queue and mark it as visited
    q.push(start);
    vis[start]=1;
    //While q is not empty 
    while(!q.empty()){
        //Take the front node
        int node1=q.front();
        // Pop it
        q.pop();
        // Print the node
        cout<<node1<<" ";
        // Traverse all the neighbors of the current node
        for(auto it:adj[node1]){
            // If not vivited the mark it as visited and push it in the queue  
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
// Time Complexity will be O(V+E)
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"BFS Traversal: "<<endl;
    bfs(0,adj,n);

}