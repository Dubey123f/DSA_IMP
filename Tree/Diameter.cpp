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
    int right=height(root->right);
    return max(left,right)+1;
}
int diameter(Node* root){
    int diameterr=0;
    if(root==nullptr){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int current_diameter=left+right;
    int left_diameter=diameter(root->left);
    int right_diameter=diameter(root->right);
    diameterr=max(diameterr,current_diameter);
   return max(diameterr,max(left_diameter,right_diameter));


}


int diameter2=0;
int d2(Node* root){
    if(root==nullptr){
        return 0;
    }
    int lh=d2(root->left);
    int rh=d2(root->right);
    diameter2=max(diameter2,lh+rh);
    return max(lh,rh)+1;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<diameter(root)<<endl;
   
    d2(root);
    cout<<diameter2<<endl;
    
}