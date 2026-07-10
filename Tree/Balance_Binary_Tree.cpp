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
int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int left=height(root->left);
    if(left==-1){
        return -1;
    }
    int right=height(root->right);
    if(right==-1){
        return -1;
    }
    if(abs(left-right)>1){
        return -1;
    }
    return max(left,right)+1;
}
bool balanceTree(Node* root){
    return height(root)!=-1;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
   if(balanceTree(root)){
    cout<<"Balanced Tree"<<endl;
   }
   else{
    cout<<"Not Balanced Tree"<<endl;
   }

}