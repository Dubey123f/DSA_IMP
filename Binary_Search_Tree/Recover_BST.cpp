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
    Node* prev1=NULL;
    Node* first=NULL;
    Node* second=NULL;
void inorder1(Node* root){
    if(root==NULL){
        return;
    }
    
    inorder1(root->left);
    if(prev1!=NULL && prev1->data>root->data){
        if(first==NULL){
            first=prev1;
            second=root;
        }
        else{
            second=root;
        }
    }
    prev1=root;
    inorder1(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
int main(){
    Node* root=new Node(3);
    root->left=new Node(1);
    root->right=new Node(4);
    root->right->left=new Node(2);
    inorder1(root);
    if(first!=NULL && second!=NULL){
        swap(first->data,second->data);
    }
    cout<<"Inorder traversal of the recovered BST is: ";
    inorder(root);
  
    return 0;
}