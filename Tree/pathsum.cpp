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
bool dfs(Node* root,int sum,int target){
    if(root==nullptr){
        return false;
    }
    sum+=root->data;
    if(root->left==nullptr && root->right==nullptr){
        return sum==target;
    }
    return dfs(root->left,sum,target) || dfs(root->right,sum,target);

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int sum=0;
    int target=5;
    if(dfs(root,sum,target)){
        cout<<"Path found with the given sum"<<endl;
    }
    else{
        cout<<"No path found with the given sum"<<endl;
    }

}