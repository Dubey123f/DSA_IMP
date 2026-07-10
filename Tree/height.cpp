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
// Height of the tree using BFS
int  height(Node* root){
    if(root==NULL){
        return 0;

    }
    queue<Node*>q;
    q.push(root);
    int c=0;
    while(!q.empty()){
       
        int  size=q.size();
        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }

        }
         c++;
    }
    return c;
}

// Height of the tree using DFS
int height2(Node* root){
    if(root==nullptr){
        return 0;
    }
    int lh=height2(root->left);
    int rh=height2(root->right);
    return max(lh,rh)+1;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<"The height of the tree is: "<<height(root)<<endl;
    cout<<"The height of the tree using DFS is: "<<height2(root)<<endl;


}