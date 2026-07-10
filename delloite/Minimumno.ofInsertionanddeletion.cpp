#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
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
    return dp[n][m];
}
pair<int,int> minInsertanddelete(string x, string y){
    int n = x.length();
    int m = y.length();
    int L = lcs(x, y, n, m);

    return {n - L, m - L}; 
}

int main(){
    string x,y;
    cout<<"Enter the first string: ";
    cin>>x;
    cout<<"Enter the second string: ";
    cin>>y;
    int n=x.length();
    int m=y.length();
   auto ans = minInsertanddelete(x, y);
cout << "Minimum Deletions: " << ans.first << endl;
cout << "Minimum Insertions: " << ans.second << endl;
}