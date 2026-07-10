#include<bits/stdc++.h>
using namespace std;
//Print the longest commmon subsequence 
string printLCS(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int index=dp[n][m];
    string lcs="";
    int i=n,j=m;
    while(i>0&&j>0){
        if(x[i-1]==y[j-1]){
            lcs.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;


}
int main(){
    string x,y;
    cout<<"Enter the first string: ";
    cin>>x;
    cout<<"Enter the second string: ";
    cin>>y;
    int n=x.length();
    int m=y.length();
    cout<<"The Longest Common Subsequence is: "<<printLCS(x,y,n,m)<<endl;

}