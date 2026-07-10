Ques:1-// DFS Algorithm
// class Solution {
//   private:
//     void dfs(int node,vector<vector<int>>& adj,int vis[],vector<int>&ls){
//         vis[node]=1;
//         ls.push_back(node);
//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 dfs(it,adj,vis,ls);
//             }
//         }
//     }
//   public:
   
//     vector<int> dfs(vector<vector<int>>& adj) {
//   int n=adj.size();
//   int vis[n]={0};
//   int start=0;
//   vector<int> ls;
//   dfs(start,adj,vis,ls);
//   return ls;
  
      
//     }
// };

Ques:2-// Number of Provinces:
// class Solution {
//     void dfs(int node,vector<vector<int>>&isL,vector<int>&vis){
//         vis[node]=1;
//         for(auto it:isL[node]){
//             if(!vis[it]){
//                 dfs(it,isL,vis);
//             }
//         }

//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//        vector<vector<int>>isL(n);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j]==1 && i!=j){
//                 isL[i].push_back(j);
//                 isL[j].push_back(i);
//                 }
//             }
//         }
//       vector<int>vis(n,0);
//        int c=0;
//        for(int i=0;i<n;i++){
//         if(!vis[i]){
//             c++;
//             dfs(i,isL,vis);
//         }
//        }
//        return c;
//     }
// };
Ques:3- // Number of Islands

// class Solution {
//     private:
//     void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&v){
//         vis[i][j]=1;
        
//         queue<pair<int,int>>q;
//         q.push({i,j});
//         int n=v.size();
//         int m=v[0].size();
//             int delRow[] = {-1, 0, +1, 0};
//     int delCol[] = {0, +1, 0, -1};
//         while(!q.empty()){
//             int i=q.front().first;
//             int j=q.front().second;
//             q.pop();
//             // for(int row=-1;row<=1;row++){
//             // for(int col=-1;col<=1;col++){
//                for(int k=0;k<4;k++){
// int nr=i+delRow[k];
// int nc=j+delCol[k];
// if(nr>=0 && nr<n && nc>=0 && nc<m && v[nr][nc]=='1' && !vis[nr][nc]){
//     vis[nr][nc]=1;
//     q.push({nr,nc});
// }
            
//         }
//         }

//     }
// public:
//     int numIslands(vector<vector<char>>& v) {
//         int n=v.size();
//         int m=v[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         int c=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!vis[i][j] && v[i][j]=='1'){
//                     c++;
//                     bfs(i,j,vis,v);
//                 }
//             }
//         }
//         return c;
//     }
// };


Ques:4-// Flood Fill Algorithm
// This algorithm is used to fill a connected component in an image with a new color.

// class Solution {
//     void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int delR[],int delC[],int iniC){
//         ans[row][col]=color;
//         int n=image.size();
//         int m=image[0].size();
//         for(int i=0;i<4;i++){
// int nrow=row+delR[i];
// int ncol=col+delC[i];
// if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol]==iniC && ans[nrow][ncol]!=color){
//     dfs(nrow,ncol,ans,image,color,delR,delC,iniC);
// }
//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int iniC= image[sr][sc];
//         vector<vector<int>> ans=image;
//        int delR[]={-1,0,1,0};
//        int delC[]= {0,1,0,-1};
//        dfs(sr,sc,ans,image,color,delR,delC,iniC);
//        return ans;
//     }
// };

Ques:5- // Rotting Oranges
// This algorithm is used to find the minimum time required to rot all oranges in a grid.
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         queue<pair<pair<int,int>,int>>q;
//         // vector<vector<int>>vis;
//         int vis[n][m];
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//                 else{
//                     vis[i][j]=0;
//                 }
//             }
//         }
//         int tn=0;
//         int delR[]={-1,0,1,0};
//         int delC[]={0,1,0,-1};
        
//         while(!q.empty()){
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int t=q.front().second;
//             tn=max(tn,t);
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nr=r+delR[i];
//                 int nc=c+delC[i];
//                   if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2){
//                 q.push({{nr,nc},t+1});
//                 vis[nr][nc]=2;
//             }
//             }
          
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j]!=2 && grid[i][j]==1){
//                     return -1;
//                 }
//             }
//         }
//         return tn;
//     }
// };

Ques:6- // Detect Cycle in an Undirected Graph
// This algorithm is used to detect a cycle in an undirected graph using DFS.
// class Solution {
//     bool detect(int src,int parent,vector<int>adj[],vector<int>& vis){
//         vis[src]=1;
//         for(auto it: adj[src]){
//             if(!vis[it]){
//                 if(detect(it,parent,adj,vis)){
//                     return true;
//                 }
//             }
//             else if(it!=parent){
//                 return true;
//             }

//         }
//         return false;
//     }
// public:
//     bool containsCycle(vector<vector<char>>& grid) {
//         int n=grid.size();
//         vector<int> adj[n];
//         for(auto it: grid){
// adj[it[0]].push_back(it[1]);
// adj[it[1]].push_back(it[0]);

//         }

//         vector<int> vis(n,0);
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 if(detect(1,-1,adj,vis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };



//Leetcode- 1559. Detect Cycles in 2D Grid


// class Solution {
//     bool detect(int x,int y ,int fx, int fy,vector<vector<char>>&  grid, vector<vector<int>>& vis,int delR[],int delC[],char ch){
//         vis[x][y]= 1;
//         int n=grid.size();
//         int m=grid[0].size();

//         // int delR[]={-1,0,1,0};
//         // int delC[]={0,1,0,-1};
//         for(int i=0;i<4;i++){
//             int nr=x+delR[i];
//             int nc=y+delC[i];
//             if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==ch){
//                 if(!vis[nr][nc]){
//                           if(detect(nr,nc,x,y,grid,vis,delR,delC,ch)){
//                     return true;
//                 }
//                 }
//                 else if(nr!=fx && nc!=fy){
//                     return true;
//                 }
             
//             }
//         }
//         return false;
        
//     }
// public:
//     bool containsCycle(vector<vector<char>>& grid) {
//         int n=grid.size();
//      int m=grid[0].size();
//      vector<vector<int>>vis(n,vector<int>(m,0));
//        int delR[]={-1,0,1,0};
//         int delC[]={0,1,0,-1};
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!vis[i][j]){
//                     if(detect(i,j,-1,-1,grid,vis,delR,delC,grid[i][j])){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

Ques:7-// Leetcode- 542. 01 Matrix or Distance Of Nearest Cell Having 1 In A Binary Matrix

// This algorithm is used to update a matrix such that each cell contains the distance to the nearest

// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         vector<vector<int>>dis(n,vector<int>(m,0));
//         queue<pair<pair<int,int>,int>>q;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j]==0){
//                     q.push({{i,j},0});
//                     vis[i][j]=1;
//                 }
//                 else{
//                     vis[i][j]=0;
//                 }
//             }
//         }

//         int delR[]={-1,0,1,0};
//         int delC[]={0,1,0,-1};
//         while(!q.empty()){
//             int row=q.front().first.first;
//             int col=q.front().first.second;
//             int steps=q.front().second;
//             q.pop();
//             dis[row][col]=steps;
//             for(int i=0;i<4;i++){
//                 int nr=row+delR[i];
//                 int nc=col+delC[i];
//                 if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
//                     q.push({{nr,nc},steps+1});
//                     vis[nr][nc]=1;
//                 }
//             }
//         }
//         return dis;
//     }
// };