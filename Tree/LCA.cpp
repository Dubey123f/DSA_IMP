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
Node* lca(Node* root,int n1,int n2){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* left=lca(root->left,n1,n2);
    Node* right=lca(root->right,n1,n2);
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    if(left!=nullptr){
        return left;
    }
    return right;

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int n1=4;
    int n2=5;
    Node* ans=lca(root,n1,n2);
    if(ans!=nullptr){
        cout<<"LCA of "<<n1<<" and "<<n2<<" is "<<ans->data<<endl;
    }
    else{
        cout<<"LCA does not exist"<<endl;
    }

}
