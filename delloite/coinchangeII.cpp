// Return the minimum number of combinations that make up that amount.

#include<bits/stdc++.h>
using namespace std;
int coinchageII(vector<int>&coin,int sum){
    int n=coin.size();
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=INT_MAX-1;
            }
            if(j==0){
                dp[i][j]=0;
            }
        }
        
    }

    for(int j=1;j<sum+1;j++){
            if(j%coin[0]==0){
                dp[1][j]=j/coin[0];
            }
            else{
                dp[1][j]=INT_MAX-1;
            }
        }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i-1]]+1);
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
    int result=coinchageII(coin,sum);
    if(result==INT_MAX-1){
        cout<<"It is not possible to make the target sum with the given coin denominations."<<endl;
    }
    else{
        cout<<"The minimum number of combinations to make the target sum is: "<<result<<endl;
    }

}