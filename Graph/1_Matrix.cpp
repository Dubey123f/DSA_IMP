#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //Create a queue to store the coordinates of the cells which are 0
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                q.push({i,j});
            }
        }
    }
    //Create a distance matrix to store the distance of each cell from the nearest 0 cell
    vector<vector<int>>dist(n,vector<int>(m,0));
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty()){
        //Get the front element of the queue
        auto it=q.front();
        //Pop the front element of the queue
        q.pop();
        // i and j (row and column) are the coordinates of the current cell
        int i=it.first;
        int j=it.second;
        //Iterate through the 4 directions and update the distance of the adjacent cells if they are 1
        for(int d=0;d<4;d++){
            //ni and nj are the coordinates of the adjacent cell in the current direction
            int ni=i+dx[d];
            int nj=j+dy[d];
            //Check if the adjacent cell is within the grid and is 1, then update its distance and push it in the queue
            if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]==1){
                grid[ni][nj]=0;
                dist[ni][nj]=dist[i][j]+1;
                q.push({ni,nj});
            }

        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
     
};
