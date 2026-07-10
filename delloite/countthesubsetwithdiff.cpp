
// THIS PROBLEM IS ALSO KNOWN AS "COUNT OF SUBSETS WITH GIVEN DIFFERENCE" AND  "TARGET SUM"

#include<bits/stdc++.h>
using namespace std;
int countsubsetsum(vector<int>&arr,int n,int s){
    int dp[n+1][s+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}
int countsubsetswithdiff(vector<int>&arr,int diff){
    int n=arr.size();
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    int sum=(diff+s)/2;
    return countsubsetsum(arr,n,sum);
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
    int diff;
    cout<<"Enter the difference: ";
    cin>>diff;
    cout<<"The count of subsets with given difference is: "<<countsubsetswithdiff(arr,diff)<<endl;

}