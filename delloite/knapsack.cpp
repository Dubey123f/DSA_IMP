#include<bits/stdc++.h>
using namespace std;

//Tabulation Approach
int dp[1002][1002];
int knapsack(int W,vector<int>&wt,vector<int>&val,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                 dp[i][j]=0;
            }
            
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
        }
    }
    
}
    return dp[n][W];
}
//Memoization Approach
// vector<vector<int>>dp(1001,vector<int>(1001,-1));
// int dp[1001][1001];

// int knapsack(int W,vector<int>&wt,vector<int>&val,int n){
//     if(n==0 || W==0){
//         return 0;
//     }
//     if(dp[n][W]!=-1){
//         return dp[n][W];
//     }
//     if(wt[n-1]<=W){
//         dp[n][W]=max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
//         return dp[n][W];
//     }
//     else{
//         dp[n][W]=knapsack(W,wt,val,n-1);
//         return dp[n][W];
//     }
// }

//Recursive Approach
// int knapsack(int W,vector<int>&wt,vector<int>&val,int n){
//     if(n==0 || W==0){
//         return 0;
//     }
//     if(wt[n-1]<=W){
//         return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
//     }
//     if(wt[n-1]>W){
//         return knapsack(W,wt,val,n-1);
//     }
// }
int main(){
int n;
cout<<"Enter the number of items: ";
cin>>n;
vector<int>wt(n);
vector<int>val(n);
cout<<"Enter the weights of the items: ";
for(int i=0;i<n;i++){
    cin>>wt[i];
}
cout<<"Enter the values of the items: ";
for(int i=0;i<n;i++){
    cin>>val[i];
}
int W;
cout<<"Enter the maximum weight capacity of the knapsack: ";
cin>>W;
// memset(dp,-1,sizeof(dp));
cout<<"The maximum value in the knapsack is: "<<knapsack(W,wt,val,n)<<endl;

}