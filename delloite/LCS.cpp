#include<bits/stdc++.h>
using namespace std;

// LONGEST COMMON SUBSEQUENCE (LCS) - RECURSIVE APPROACH
// int LCS(string x,string y,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(x[n-1]==y[m-1]){
//         return 1+LCS(x,y,n-1,m-1);
//     }
//     else{
//         return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
//     }
    
// }

//Memoization Approach
// int static dp[1001][1001];
// int LCS(string x,string y,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
// if(x[n-1]==y[m-1]){
//    return dp[n][m]=1+LCS(x,y,n-1,m-1);
// }
// else{
//   return  dp[n][m]=max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
// }

// }

//Top-Down Dynamic Programming Approach
int LCS(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string x,y;
    cout<<"Enter the first string: ";
    cin>>x;
    cout<<"Enter the second string: ";
    cin>>y;
    // memset(dp,-1,sizeof(dp));
    int n=x.length();
    int m=y.length();
    cout<<"The length of the Longest Common Subsequence is: "<<LCS(x,y,n,m)<<endl;


}