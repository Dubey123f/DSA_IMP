#include<bits/stdc++.h>
#include<vector>
using namespace std;
// int main(){
//     vector<int>arr={1,2,3,4,5};
//     vector<int>dp(arr.size());
//     dp[0]=arr[0];
//     for(int i=1;i<arr.size();i++){
//         dp[i]=dp[i-1]+arr[i];
//     }
//     cout<<dp[arr.size()-1];
// }
//Maximum sum of non-adjacent elements
// int main(){
//     vector<int>arr={2,-3,5,-8,7};
//     vector<int>dp(arr.size());
//     dp[0]=max(0,arr[0]);
//     dp[1]=max(dp[0],arr[1]);
//     for(int i=2;i<arr.size();i++){
//         dp[i]=max(dp[i-1],arr[i]+dp[i-2]);

//     }
//     cout<<dp[arr.size()-1];
//     return 0;
// }
//Subset of array with no adjecent elements
// int main(){
//     vector<int>arr={2,3,4,-8,2};
//     vector<int>arr2={-5,8,3,1,-4};
//     vector<int>dp(arr.size()+1);
//     dp[1]=max(arr[1],arr2[1]);
//     dp[2]=max(dp[1],max(arr[2],arr2[2]));
//     for(int i=3;i<=arr.size();i++){
//         dp[i]=max(dp[i-1],max(arr[i]+dp[i-2],arr2[i]+dp[i-2]));
//     }
//     cout<<dp[arr.size()];
// }

// Problem Statement
// Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

// The vacation consists of 
// N days. For each 
// i (
// 1≤i≤N), Taro will choose one of the following activities and do it on the 
// i-th day:

// A: Swim in the sea. Gain 
// a 
// i
// ​
//   points of happiness.
// B: Catch bugs in the mountains. Gain 
// b 
// i
// ​
//   points of happiness.
// C: Do homework at home. Gain 
// c 
// i
// ​
//   points of happiness.
// As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

// Find the maximum possible total points of happiness that Taro gains.
// int main(){
//     vector<int>arr={10,20,30};
//     vector<int>arr2={40,50,60};
//     vector<int>arr3={70,80,90};
//     int n=arr.size();
//     vector<int>dpa(n);
//     vector<int>dpb(n);
//     vector<int>dpc(n);
//     dpa[0]=arr[0];
//     dpb[0]=arr2[0];
//     dpc[0]=arr3[0];
//     for(int i=1;i<n;i++){
//         dpa[i]=arr[i]+max(dpb[i-1],dpc[i-1]);
//         dpb[i]=arr2[i]+max(dpa[i-1],dpc[i-1]);
//         dpc[i]=arr3[i]+max(dpa[i-1],dpb[i-1]);
//     }
//     cout<<dpa[n-1]<<" "<<dpb[n-1]<<" "<<dpc[n-1]<<endl;
//     cout<<max(dpa[n-1],max(dpb[n-1],dpc[n-1]));
// }


//Visit This for Problem Description:https://www.desiqna.in/10567/barclays-sde-coding-oa-questions-and-solutions-set-8-2022-dp
// int main(){
//     int n;
//     cin>>n;
//     int v;
//     cin>>v;
//     vector<int>easy(n+1);
//     vector<int>hard(n+1);
//     int i=1;
//     while(i<=n){
//         cin>>easy[i];
//         cin>>hard[i];
//         i++;
//     }
//     int dp[20005][5];
//     dp[1][1]=easy[1];
//     dp[1][2]=hard[1]; 
//     dp[1][3]=0;
//     for(int i=2;i<=n;i++){
//         dp[i][1] = easy[i] + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
//         dp[i][2] = hard[i] + dp[i-1][3] ;
//         dp[i][3] = 0 + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
//     }
//     cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
// }

//Visit this link for the problem description:https://www.desiqna.in/11291/cisco-coding-solutions-2023-dynamic-programming-kings-walk
// int main(){
//     int n;
//     int m;
//     cin>>n;
//     cin>>m;
//     vector<vector<int>>dp(n+1,vector<int>(m+1));
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             // dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             if(i==1 && j==1){
//                 dp[i][j]=1;
//             }
//             else{
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];

//             }
//         }
//     }
//     cout<<dp[n][m];
// }


//Knapsack:
// int main(){
//     int n;
//     cin>>n;
//     int c;
//     cin>>c;
//     vector<int>wt(n);
//     vector<int>profit(n);
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>profit[i];
//     }
//     vector<vector<int>>dp(n+1,vector<int>(c+1));
//     for(int i=1;i<=c;i++){
//         dp[0][i]=0;
//     }
//     for(int i=1;i<=n;i++){
//         dp[i][0]=0;
//         for(int j=1;j<=c;j++){
//             if(wt[i-1]<=j){
//                 dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-wt[i-1]]);
//             }
//         }
//     }
//     cout<<dp[n][c];
// }
//Knapsack variations having two capacity c1 and c2 and single weight array:
// int main(){
//     int n;
//     cin>>n;
//     int c1;
//     cin>>c1;
//     int c2;
//     cin>>c2;
//     vector<int>wt(n);
//     vector<int>profit(n);
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>profit[i];
//     }
//     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(c1+1,vector<int>(c2+1)));
//     for(int i=1;i<=c1;i++){
//         for(int j=1;j<=c2;j++){
//             dp[0][i][j]=0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=c1;j++){
//             for(int k=1;k<=c2;k++){
//                 if(wt[i-1]<=j && wt[i-1]<=k){
//                     dp[i][j][k]=max(dp[i-1][j][k],profit[i-1]+dp[i-1][j-wt[i-1]][k-wt[i-1]]);
//                 }
//                 else {
//                     dp[i][j][k] = dp[i - 1][j][k];
//                 }
//             }
//         }
//     }
//     cout<<dp[n][c1][c2];
// }



//4-Dimensional Knapsack Problem
// int main(){
//     int n;
//     cin>>n;
//     int c1;
//     cin>>c1;
//     int c2;
//     cin>>c2;
//     int c3;
//     cin>>c3;
//     vector<int>wt(n);
//     vector<int>profit(n);
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>profit[i];
//     }
//     vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(c1+1,vector<vector<int>>(c2+1,vector<int>(c3+1,0))));
//     for(int i=1;i<=c1;i++){
//         for(int j=1;j<=c2;j++){
//             for(int k=1;k<=c3;k++){
//                 dp[0][i][j][k]=0;
//             }
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=c1;j++){
//             for(int k=1;k<=c2;k++){
//                 for(int l=1;l<=c3;l++){
//                     // if(wt[i-1]<=j && wt[i-1]<=k && wt[i-1]<=l){
//                     //     dp[i][j][k][l]=max(dp[i-1][j][k][l],profit[i-1]+dp[i-1][j-wt[i]][k][l],profit[i-1]+dp[i-1][j][k-wt[i]][l],profit[i-1]+dp[i-1][j][k][l-wt[i]]);
//                     // }
//                     // else {
//                     //     dp[i][j][k][l] = dp[i - 1][j][k][l];
//                     // }
                    
//                     dp[i][j][k][l] = dp[i - 1][j][k][l]; // not take

//                     if (wt[i - 1] <= j)
//     dp[i][j][k][l] = max(dp[i][j][k][l],
//         profit[i - 1] + dp[i - 1][j - wt[i - 1]][k][l]);

// else if (wt[i - 1] <= k)
//     dp[i][j][k][l] = max(dp[i][j][k][l],
//         profit[i - 1] + dp[i - 1][j][k - wt[i - 1]][l]);

// else if (wt[i - 1] <= l)
//     dp[i][j][k][l] = max(dp[i][j][k][l],
//         profit[i - 1] + dp[i - 1][j][k][l - wt[i - 1]]);

//                 }
//             }
//         }
//     }
//     cout<<dp[n][c1][c2][c3];
// }


// Sum of subset:

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     if (!(cin >> n >> k)) return 0;
//     vector<int> b(n);
//     int sum = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> b[i];
//         sum += b[i];
//     }

//     if (k > sum) { // quick check
//         cout << "Nope";
//         return 0;
//     }

//     // dp[i][j] = can we get sum j using first i items
//     vector<vector<char>> dp(n + 1, vector<char>(k + 1, 0));
//     dp[0][0] = 1;

//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= k; ++j) {
//             // not take
//             if (dp[i - 1][j]) dp[i][j] = 1;
//             // take if possible
//             else if (j >= b[i - 1] && dp[i - 1][j - b[i - 1]]) dp[i][j] = 1;
//             // else remains 0
//         }
//     }
// int c=0;
// if(dp[n][k]){
//     c++;
// }
// cout<<c;
//     cout << (dp[n][k] ? "Yup" : "Nope");
//     return 0;
// }
// int main(){
//     int n;
//     cin>>n;
//     int k;
//     cin>>k;
//     vector<int>b(n);
//     int s=0;
//     for(int i=1;i<=n;i++){
//         cin>>b[i];
//         s+=b[i];
//     }
//     // vector<int>dp(n+1);
//     bool dp[5005][5005];
//     dp[0][0]=true;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=k;j++){
//             if(dp[i-1][j]==true){
//                 dp[i][j]=true;
//             }
//             else if(dp[i-1][j-b[i]]==true){
//                 dp[i][j]=true;
//             }
//             else{
//                 dp[i][j]=false;
//             }
//         }
//     }
//     if(dp[n][k]!=true){
//         cout<<"Nope";
//     }
//     else{
//         cout<<"Yup";
//     }
//     return 0;
// }


// Hrader version of sum of subset problem
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     if (!(cin >> n >> k)) return 0;

//     vector<int> b(n);
//     for (int i = 0; i < n; ++i) cin >> b[i];

//     // dp[i][j] = number of subsets using first i items that sum to j
//     vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
//     dp[0][0] = 1;

//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= k; ++j) {
//             dp[i][j] = dp[i - 1][j];                     // don't take b[i-1]
//             if (j >= b[i - 1]) dp[i][j] += dp[i - 1][j - b[i - 1]]; // take b[i-1]
//         }
//     }

//     cout << dp[n][k] << '\n';
//     return 0;
// }

// Link of Problem Description:https://www.desiqna.in/11154/uber-hard-dynamic-programming-coding-questions-solutions
int mxi(int x,int y,int z){
    return max(x,max(y,z));
}
int main(){
    int n;
    cin>>n;
    vector<int>b(n+1);
    vector<int>d(n+1);
    int dp[10000+5][5][5];
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
       for(int i=1;i<=n;i++){
        cin>>d[i];
    }
   dp[1][1][1]=b[1];
   dp[1][1][2]=b[1];
   dp[1][2][2]=d[1];
   dp[1][2][1]=d[1];
   for(int i=2;i<=n;i++){
    dp[i][1][1] = b[i] + b[i-1] + max(dp[i-2][2][2],dp[i-2][2][1]);
        dp[i][1][2] = b[i] + d[i-1] + mxi(dp[i-2][1][1],dp[i-2][1][2],dp[i-2][2][1]);
        dp[i][2][1] = d[i] + b[i-1] + mxi(dp[i-2][2][1],dp[i-2][2][2],dp[i-2][1][2]);
        dp[i][2][2] = d[i] + d[i-1] + max(dp[i-2][1][2],dp[i-2][1][1]);
   }
   cout<<max(dp[n][1][1],max(dp[n][1][2],max(dp[n][2][1],dp[n][2][2])));

}
