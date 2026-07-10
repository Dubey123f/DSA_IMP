// Subset Sum Problem using Dynamic Programming

#include<bits/stdc++.h>
using namespace std;
// Function to determine if there is a subset with sum equal to target
bool subset(vector<int>&arr,int n,int sum){

    int dp[n+1][sum+1];
     for(int i = 0; i <= n; i++) {
        dp[i][0] = true;   // sum 0 is always possible
    }
    for(int j = 1; j <= sum; j++) {
        dp[0][j] = false; // no elements, positive sum impossible
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
    if(subset(arr,n,sum)){
        cout<<"There exists a subset with the given sum."<<endl;
    }
    else{
        cout<<"No subset with the given sum exists."<<endl;
    }

}