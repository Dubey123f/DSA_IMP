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
bool foundp=false;
bool foundq=false;
Node* lca(Node* root,Node* p,Node* q){
    if(root==nullptr){
        return nullptr;
    }
    
    Node* left=lca(root->left,p,q);
    Node* right=lca(root->right,p,q);
     if(root==p){
        foundp=true;
       
     }
        if(root==q){
            foundq=true;
           
        }


    if(root==p || root==q){
        return root;
    }
  
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
    Node* p=root->left->left;
    Node* q=root->left->right;
    Node* ans=lca(root,p,q);
    if(foundp && foundq && ans!=nullptr){
        cout<<"LCA of "<<p->data<<" and "<<q->data<<" is "<<ans->data<<endl;
    }
    else{
        cout<<"LCA does not exist"<<endl;
    }
    return 0;
}