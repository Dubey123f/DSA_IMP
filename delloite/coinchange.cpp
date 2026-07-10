#include<bits/stdc++.h>
using namespace std;
int coinchange(vector<int>&coin,int sum){
    int n=coin.size();
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cout<<"Enter the number of coin denominations: ";
    cin>>n;
    vector<int>coin(n);
    cout<<"Enter the coin denominations: ";
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    int sum;
    cout<<"Enter the target sum: ";
    cin>>sum;
    cout<<"The number of ways to make the target sum is: "<<coinchange(coin,sum)<<endl;

}