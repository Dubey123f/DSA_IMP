#include<bits/stdc++.h>
using namespace std;
int count(vector<int>&arr,int n,int sum){
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
            if(arr[i-1]<=j){
             dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
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
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter the target sum: ";
    cin>>sum;
    cout<<"The number of subsets with the given sum is: "<<count(arr,n,sum)<<endl;

}