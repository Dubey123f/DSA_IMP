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
struct Info{
    int size;
    int min;
    int max;
    int ans;
    int sum;
    bool isBST;
};
void solve(Node* root,Info &res){
    if(root==NULL){
        res.size=0;
        res.min=INT_MAX;
        res.max=INT_MIN;
        res.ans=0;
        res.sum=0;
        res.isBST=true;
        return;
    }
    Info left,right;
    solve(root->left,left);
    solve(root->right,right);
    res.size=1+left.size+right.size;
  
    if(left.isBST && right.isBST && root->data>left.max && root->data<right.min){
        res.min=min(root->data,left.min);
        res.max=max(root->data,right.max);
        res.ans=res.size;
        res.sum=root->data+left.sum+right.sum;
        res.isBST=true;
    }
    else{
        res.ans=max(left.ans,right.ans);
        res.sum=max(left.sum,right.sum);
        res.isBST=false;
    }


}
int main(){
    Node* root=new Node(50);
    root->left=new Node(30);
    root->right=new Node(60);
    root->left->left=new Node(5);
    root->left->right=new Node(20);
    root->right->right=new Node(70);
    Info res;
    solve(root,res);
    cout<<"Size of the largest BST in the given binary tree is: "<<res.ans<<endl;
    cout<<"Sum of the largest BST in the given binary tree is: "<<res.sum<<endl;
    return 0;
}