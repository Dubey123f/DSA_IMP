// 221. Maximal Square
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of rows and columns:";
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m));
    cout<<"Enter the matrix elements (0 or 1):";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(m,0));
    int maxside=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j]=mat[i][j]-'0';
                maxside=max(maxside,dp[i][j]);

            }
            else if(mat[i][j]=='1'){
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                maxside=max(maxside,dp[i][j]);
            }

        }
        
    }
    cout<<"The area of the largest square is: "<<maxside*maxside<<endl;
}