#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        string x;
        cin >> x;
        if(x == "INF"){
            grid[i][j] = INT_MAX;
        }
        else{
            grid[i][j] = stoi(x);
        }
    }
}
    for(int i=0;i<n;i++){
        grid[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][k]!=INT_MAX && grid[k][j]!=INT_MAX && grid[i][k]+grid[k][j]<grid[i][j]){
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==INT_MAX){
                cout<<"INF"<<" ";
            }
            else{
                cout<<grid[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}

