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
    //queue bana aur usme starting cell ke coordinates aur distance 1 push karo, aur grid[0][0] ko 1 mark karo taki usko visited mark kiya jaye
queue<pair<pair<int,int>,int>>q;
//Agar starting cell ya ending cell me 1 hai to shortest path nahi hoga, to -1 print karo aur return karo
if(grid[0][0]==1 || grid[n-1][m-1]==1){
    cout<<"Shortest Path: -1"<<endl;
    return 0;

}
//8 direction me move karne ke liye dx aur dy array bana
q.push({{0,0},1});
//grid[0][0] ko 1 mark karo taki usko visited mark kiya jaye
grid[0][0]=1;
//8 direction me move karne ke liye dx aur dy array bana
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0 ,1};
//BFS traversal karo jab tak queue empty nahi ho jata, aur har cell ke adjacent cells ko check karo, agar adjacent cell grid ke boundary ke andar hai aur usme 0 hai to usko queue me push karo aur usko visited mark karo, aur distance ko 1 se badha do
while(!q.empty()){
    //Get the front element of the queue
    auto it=q.front();
    //Pop the front element of the queue
    q.pop();
    // i and j (row and column) are the coordinates of the current cell, and dist is the distance of the current cell from the starting cell
    int i=it.first.first;
    int j=it.first.second;
    // dist is the distance of the current cell from the starting cell
    int dist=it.second;
    //Agar current cell ending cell hai to shortest path mil gaya, to dist print karo aur return karo
    if(i==n-1 && j==m-1){
        cout<<"Shortest Path: "<<dist<<endl;
        return 0;
    }
    //8 direction me move karne ke liye dx aur dy array bana, aur adjacent cells ko check karo
    for(int d=0;d<8;d++){
        //ni and nj are the coordinates of the adjacent cell in the current direction
        int ni=i+dx[d];
        //nj is the column of the adjacent cell in the current direction
        int nj=j+dy[d];
        //Check if the adjacent cell is within the grid and is 0, then push it in the queue and mark it as visited
        if(ni>=0&&nj>=0 && ni<n&&nj<m&&grid[ni][nj]==0){
            //Mark the adjacent cell as visited by setting it to 1
            grid[ni][nj]=1;
            //Push the adjacent cell in the queue with distance dist+1
            q.push({{ni,nj},dist+1});

        }

    }

}
cout<<"Shortest Path: -1"<<endl;
}