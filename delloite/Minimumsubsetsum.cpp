#include<bits/stdc++.h>
using namespace std;
// Minimum subset sum difference problemusing Dynamic programming
vector<bool> subsetsum(vector<int>&arr,int n,int s){
    vector<vector<bool>>dp(n+1,vector<bool>(s+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n];
}
int minimumsum(vector<int>&arr){
    int s=0;
    int n=arr.size();
    int mini=INT_MAX;
     for(int i=0;i<n;i++){
       s+=arr[i];
    }
    vector<bool>temp=subsetsum(arr,n,s);
   
  
    for(int i=1;i<=s/2;i++){
  if(temp[i]){
      mini=min(mini,s-2*i);
  }
    }
return mini;


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
    cout<<"The minimum subset sum difference is: "<<minimumsum(arr)<<endl;
}