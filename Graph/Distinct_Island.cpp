#include<bits/stdc++.h>
using namespace std;
//dfs function banayege jo current cell ke coordinates aur grid ko lega, aur current island ka path string me store karega
void dfs(int i,int j,vector<vector<int>>&grid,string &path){
    //Base case: Agar i aur j grid ke boundary se bahar hai ya grid[i][j] 1 nahi hai to return karo
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
        return;
    }
    //Mark the current cell as visited by setting it to 0
    grid[i][j]=0;
    //4 direction me DFS call karo aur path string me direction add karo, aur backtrack karte time path string me 'B' add karo
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    //Direction array banayege jisme 4 direction ke corresponding characters store honge
    char dir[4]={'U','D','L','R'};
    //4 direction me DFS call karo
    for(int d=0;d<4;d++){
        //ni and nj are the coordinates of the adjacent cell in the current direction
        int ni=i+dx[d];
        int nj=j+dy[d];
        //check karo ki adjacent cell grid ke boundary ke andar hai aur usme 1 hai, agar ha to us direction me DFS call karo aur path string me us direction ka character add karo, aur backtrack karte time path string me 'B' add karo
        if(ni>=0&&nj>=0 && ni<grid.size()&&nj<grid[0].size()&&grid[ni][nj]==1){
            path.push_back(dir[d]);
            dfs(ni,nj,grid,path);
            path.push_back('B');

        }

    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //Create a set to store the distinct paths of the islands
    set<string>st;
    //Iterate through the grid, agar cell me 1 hai to us cell se DFS call karo aur current island ka path string me store karo, aur us path string ko set me insert karo
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                string path="S";
                dfs(i,j,grid,path);
                st.insert(path);
            }
        }
    }
    cout<<"Number of Distinct Islands: "<<st.size()<<endl;

}