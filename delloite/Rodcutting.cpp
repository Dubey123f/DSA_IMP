#include<bits/stdc++.h>
using namespace std;
int rodcutting(vector<int>&price,int n,int length){
    int dp[n+1][length+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<length+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<length+1;j++){
            if(i<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][length];
}
int main(){
    int n;
    cout<<"Enter the number of pieces: ";
    cin>>n;
    vector<int>price(n);
    cout<<"Enter the prices of the pieces: ";
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int length;
    cout<<"Enter the length of the rod: ";
    cin>>length;
    cout<<"The maximum obtainable value is: "<<rodcutting(price,n,length)<<endl;

}