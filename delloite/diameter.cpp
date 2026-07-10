#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));

}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int currdiameter=lh+rh;
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"The diameter of the tree is: "<<diameter(root)<<endl;
}