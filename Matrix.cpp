#include<bits/stdc++.h>
#include<vector>
using namespace std;
// void traverse(int i, int j, int n, int m, vector<vector<int>>& grid) {
//     if(i == n-1 && j == m-1) {
//         cout << grid[i][j] << " reached\n";
//         return;
//     }

//     // Move Down
//     if(i + 1 < n)
//         traverse(i+1, j, n, m, grid);
    
//     // Move Right
//     if(j + 1 < m)
//         traverse(i, j+1, n, m, grid);
// }
// int totalSum = 0;

// void dfs(int i, int j, int currentSum, vector<vector<int>>& grid, int n, int m) {
//     currentSum += grid[i][j];

//     if(i == n-1 && j == m-1) {
//         totalSum += currentSum;
//         return;
//     }

//     if(i + 1 < n) dfs(i + 1, j, currentSum, grid, n, m);
//     if(j + 1 < m) dfs(i, j + 1, currentSum, grid, n, m);
// }
vector<int> pathSums;
void dfs(int i, int j, int currentSum, vector<vector<int>>& grid, int n, int m) {
    currentSum += grid[i][j];

    // If reached bottom-right → store the sum
    if (i == n-1 && j == m-1) {
        pathSums.push_back(currentSum);
        return;
    }

    // Move Down
    if (i + 1 < n) {
        dfs(i + 1, j, currentSum, grid, n, m);
    }

    // Move Right
    if (j + 1 < m) {
        dfs(i, j + 1, currentSum, grid, n, m);
    }
}


int main(){
    int n,m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    cout<<"Enter the elements in the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The entered matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<"Calculating total sum of all paths..."<<endl;
    dfs(0, 0, 0, matrix, n, m);
    // cout << "Total Sum of all paths from (0,0) to (" << n-1 << "," << m-1 << ") is: " << totalSum << endl;
    int c=0;
for (int sum : pathSums){
 cout << sum << " ";
 if(sum%5==0){
    c++;
 }
}
       
    cout << "Count of path sums divisible by 5: " << c << endl;

}