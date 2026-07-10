#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //create a time variable to count the time taken to rot all the oranges
    int time=0;
    //Create a fresh variable to count the number of fresh oranges
    int fresh=0;
    //Create a queue to store the rotten oranges
    queue<pair<int,int>>q;
    //Iterate through the grid and push the rotten oranges in the queue and count the number of fresh oranges
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    //Create two arrays to store the 4 directions
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    //BFS Traversal
    while(!q.empty()){
        //Get the size of the queue
        int size=q.size();
        //Iterate through the queue and rot the adjacent fresh oranges
        for(int k=0;k<size;k++){
            //Get the front element of the queue
            auto it=q.front();
            //Pop the front element of the queue
            q.pop();
            // i and j (row and column) are the coordinates of the rotten orange
            int i=it.first;
            int j=it.second;
            //iterare through the 4 directions 
           for(int d=0;d<4;d++){
            //ni and nj are the coordinates of the adjacent cell in the current direction
            int ni=i+dx[d];
            int nj=j+dy[d];
            //Check if the adjacent cell is within the grid and is a fresh orange
            if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]==1){
                grid[ni][nj]=2;
                q.push({ni,nj});
                fresh--;
            }
           }
        }
        if(!q.empty()){
            time++;
        }
    }
    if(fresh==0){
        cout<<time<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}