#include<bits/stdc++.h>
using namespace std;
int unboundedknapsack(vector<int>&w,int n,vector<int>&val,int W){
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int>w(n),val(n);
    cout<<"Enter the weights of the items: ";
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"Enter the values of the items: ";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int W;
    cout<<"Enter the maximum weight capacity of the knapsack: ";
    cin>>W;
    cout<<"The maximum value in the knapsack is: "<<unboundedknapsack(w,n,val,W)<<endl;

}