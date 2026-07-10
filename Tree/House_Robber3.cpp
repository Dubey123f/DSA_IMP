#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
pair<int,int>dfs(Node* root){
    if(root==nullptr){
        return {0,0};
    }
    auto left=dfs(root->left);
    auto right=dfs(root->right);
    int include=root->data+left.second+right.second;
    int exclude=max(left.first,left.second)+max(right.first,right.second);
    return {include,exclude};
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    auto ans=dfs(root);
    cout<<max(ans.first,ans.second)<<endl;
}