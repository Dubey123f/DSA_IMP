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
int maxsum=INT_MIN;
int dfs(Node* root){
    if(root==nullptr){
        return 0;
    }
    int lh=max(0,dfs(root->left));
    int rh=max(0,dfs(root->right));
    maxsum=max(maxsum,root->data+lh+rh);
    return root->data+max(lh,rh);

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    dfs(root);
    cout<<maxsum<<endl;

}