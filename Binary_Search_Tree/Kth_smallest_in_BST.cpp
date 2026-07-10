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
void inorder(Node* root,int k){
    if(root==NULL) return;
    static int c=0;
    inorder(root->left,k);
    c++;
    if(c==k){
        cout<<"Kth smallest element in BST is: "<<root->data<<endl;
        return;
    }
    inorder(root->right,k);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->right=new Node(7);
    int k=3;
    inorder(root,k);
    return 0;
}
//Note:For Kth largest element in BST, we can do reverse inorder traversal and keep track of count until we reach k.
