#include<bits/stdc++.h>
using namespace std;
//Space Optimized Approach
int func(int n,int m){
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0){
                    up=prev[j];

                }
                if(j>0){
                    left=temp[j-1];

                }
                temp[j]=up+left;
            }
            
        }
        prev=temp;
    }
    return prev[m-1];
}
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    cout<<"The number of unique paths from top-left to bottom-right is: "<<func(n,m)<<endl;
    //Tabulation Approach 
    // vector<vector<int>>dp(n,vector<int>(m,-1));

    // dp[0][0]=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 && j==0){
    //             dp[i][j]=1;
    //         }
    //         else{
    //             int up=0;
    //             int left=0;
    //             if(i>0){
    //                 up=dp[i-1][j];
    //             }
    //             if(j>0){
    //                 left=dp[i][j-1];
    //             }
    //             dp[i][j]=up+left;
    //         }
    //     }
    // }
    // cout<<"The number of unique paths from top-left to bottom-right is: "<<dp[n-1][m-1]<<endl;

}




