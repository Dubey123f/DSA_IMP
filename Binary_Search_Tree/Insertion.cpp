#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);

    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,7);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,8);
    cout<<"Root: "<<root->data<<endl;
    cout<<"Left Child: "<<root->left->data<<endl;
    cout<<"Right Child: "<<root->right->data<<endl;
    cout<<"Left-Left Child: "<<root->left->left->data<<endl;
    cout<<"Left-Right Child: "<<root->left->right->data<<endl;
    cout<<"Right-Left Child: "<<root->right->left->data<<endl;
    cout<<"Right-Right Child: "<<root->right->right->data<<endl;
    

}