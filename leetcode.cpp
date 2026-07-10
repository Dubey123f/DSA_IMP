// // Minimum Path Sum
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cout<<"Enter the number of rows and columns:"<<endl;
//     cin>>n>>m;
//     vector<vector<int>>grid(n,vector<int>(m,0));
//     cout<<"Enter the grid values:"<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }
//     vector<vector<int>>dp(n,vector<int>(m,0));
//     dp[0][0]=grid[0][0];
//     for(int i=1;i<n;i++){
//         dp[i][0]=dp[i-1][0]+grid[i][0];

//     }
//     for(int j=1;j<m;j++){
//         dp[0][j]=dp[0][j-1]+grid[0][j];
//     }
//     for(int i=1;i<n;i++){
//         for(int j=1;j<m;j++){
//             dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];

//         }
//     }
//     cout<<"The minimum path sum is: "<<dp[n-1][m-1]<<endl;
//     return 0;
// }


//Word search II
#include <bits/stdc++.h>
using namespace std;

bool isPrefix(const vector<string>& words, const string& prefix) {
    for (auto& w : words) {
        if (w.rfind(prefix, 0) == 0) return true;
    }
    return false;
}

void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited,
         vector<string>& words, set<string>& result, string current, set<string>& wordSet) {
    int n = board.size();
    int m = board[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j]) return;

    current.push_back(board[i][j]);

    if (!isPrefix(words, current)) return; // prune invalid prefix

    if (wordSet.find(current) != wordSet.end()) {
        result.insert(current);
    }

    visited[i][j] = true;

    dfs(i + 1, j, board, visited, words, result, current, wordSet);
    dfs(i - 1, j, board, visited, words, result, current, wordSet);
    dfs(i, j + 1, board, visited, words, result, current, wordSet);
    dfs(i, j - 1, board, visited, words, result, current, wordSet);

    visited[i][j] = false;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns:" << endl;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m, ' '));
    cout << "Enter the board values:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int k;
    cout << "Enter the number of words:" << endl;
    cin >> k;
    vector<string> words(k);
    cout << "Enter the words:" << endl;
    for (int i = 0; i < k; i++) {
        cin >> words[i];
    }

    set<string> result;
    set<string> wordSet(words.begin(), words.end());
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, board, visited, words, result, "", wordSet);
        }
    }

    cout << "\nThe found words are:" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}
