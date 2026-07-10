// 2435. Paths in Matrix Whose Sum Is Divisible by K
// You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

// Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    cout<<"Enter the elements in the 2D Matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int k;
    cout<<"Enter the value of K: ";
    cin>>k;
    const int MOD=1e9+7;
   vector<vector<vector<int>>> dp(
    n,
    vector<vector<int>>(m, vector<int>(k, 0))
);
    dp[0][0][grid[0][0]%k]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int r=0;r<k;r++){
                if(i>0){
                    int prevR=(r-grid[i][j]%k+k)%k;
                    dp[i][j][r]=dp[i][j][r]+dp[i-1][j][prevR];
                    dp[i][j][r]%=MOD;
                }
                if(j>0){
                    int prevR=(r-grid[i][j]%k+k)%k;
                    dp[i][j][r]=dp[i][j][r]+dp[i][j-1][prevR];
                    dp[i][j][r]%=MOD;
                }

            }

        }
        
    }
    cout << dp[n-1][m-1][0] << endl;
}