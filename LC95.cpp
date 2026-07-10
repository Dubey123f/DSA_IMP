// 95. Unique Binary Search Trees II
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:


// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 8


// The output is: Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Give me the shortest solution for this problem.
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return buildTrees(1,n);
    }
    vector<TreeNode*> buildTrees(int start,int end){
        vector<TreeNode*> allTrees;
        if(start>end){
            allTrees.push_back(nullptr);
            return allTrees;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees=buildTrees(start,i-1);
            vector<TreeNode*> rightTrees=buildTrees(i+1,end);
            for(auto left:leftTrees){
                for(auto right:rightTrees){
                    TreeNode* currTree=new TreeNode(i);
                    currTree->left=left;
                    currTree->right=right;
                    allTrees.push_back(currTree);
                }
            }
        }
        return allTrees;
    }
};
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    Solution sol;
    vector<TreeNode*> result=sol.generateTrees(n);
    cout<<"The number of unique BSTs is: "<<result.size()<<endl;
    cout<<"The trees are as follows:"<<endl;
    
    return 0;
}
