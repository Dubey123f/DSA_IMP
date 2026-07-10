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
    int min;
    int max;
   
    bool isBST;
};
bool isvalid(Node* root,Info& res){
    if(root==NULL){
        res.min=INT_MAX;
        res.max=INT_MIN;
        res.isBST=true;
        return true;
    }
    Info left,right;
    bool leftans=isvalid(root->left,left);
    bool rightans=isvalid(root->right,right);
    if(leftans && rightans && root->data>left.max && root->data<right.min){
        res.min=min(root->data,left.min);
        res.max=max(root->data,right.max);
        res.isBST=true;
        return true;
    }
    else{
        res.isBST=false;
        return false;
    }
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    Info res;
    if(isvalid(root,res)){
        cout<<"The given binary tree is a valid BST"<<endl;
    }
    else{
        cout<<"The given binary tree is not a valid BST"<<endl;
    }
    return 0;
}