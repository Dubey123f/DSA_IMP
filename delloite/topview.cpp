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

// Using DFS Approach
// void topview(Node* root,int hd,int level,map<int,pair<int,int>>&m){
//     if(root==NULL){
//         return;
//     }
//     if(m.find(hd)==m.end() || level<m[hd].second){
//         m[hd]={root->data,level};
//     }
//     topview(root->left,hd-1,level+1,m);
//     topview(root->right,hd+1,level+1,m);
// }

// Using BFS Approach
void topview(Node* root,int hd,map<int,pair<int,int>>&m){
    if(root==NULL){
        return;
    }
    queue<pair<Node*,pair<int,int>>>q;
    q.push(root,{hd,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node* curr=p.first;
        int hdp=p.second.first;
        int level=p.second.second;
        if(m.find(hdp)==m.end() || level<m[hdp].second){
            m[hdp]={curr->data,level};
        }
        if(curr->left!=NULL){
            q.push({curr->left,{hdp-1,level+1}});
        }
        if(curr->right!=NULL){
            q.push({curr->right,{hdp+1,level+1}});
        }
        
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    // root->left->right->left=new Node(7);
    // root->left->right->right=new Node(8);
    map<int,pair<int,int>>m;
    topview(root,0,0,m);
    cout<<"The top view of the binary tree is: ";
    for(auto it:m){
        cout<<it.second.first<<" ";
    }
}