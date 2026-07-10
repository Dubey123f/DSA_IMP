// 130. Surrounded Regions
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:


// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of rows and columns:";
    cin>>n>>m;
    vector<vector<char>>booard(n,vector<char>(m));
    cout<<"Enter the board elements (X or O):";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>booard[i][j];
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(booard[i][j]=='O'){
                    q.push({i,j});
                    booard[i][j]='#';

                }

            }

        }

    }
    
    int delR[]={-1,0,1,0};
    int delC[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nR=r+delR[i];
            int nc=c+delC[i];
            if(nR>=0 && nR<n && nc>=0 && nc<m && booard[nR][nc]=='O'){
                q.push({nR,nc});
                booard[nR][nc]='#';

            }

        }

    }
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(booard[i][j] == 'O')
                booard[i][j] = 'X';
            else if(booard[i][j] == '#')
                booard[i][j] = 'O';
        }
    }
    cout<<"The board after capturing surrounded regions is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<booard[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}