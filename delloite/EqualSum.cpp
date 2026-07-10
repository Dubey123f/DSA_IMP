#include<bits/stdc++.h>
using namespace std;
bool subset(vector<int>&arr,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
bool equalum(vector<int>&arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
sum=sum+arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else{
        return subset(arr,n,sum/2);
    }
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
    if(equalum(arr,n)){
        cout<<"The array can be partitioned into two subsets with equal sum."<<endl;
    }
    else{
        cout<<"The array cannot be partitioned into two subsets with equal sum."<<endl;
    }
}