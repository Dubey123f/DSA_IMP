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
int width(Node* root){
    if(root==NULL){
        return 0;
    }
    queue<pair<Node*,long long>>q;
    q.push({root,0});
    long long ans=0;
    while(!q.empty()){
        long long size=q.size();
        long long minIndex=q.front().second;
        long long first,last;
        for(int i=0;i<size;i++){
            long long currI=q.front().second-minIndex;
            Node* node=q.front().first;
            q.pop();
            if(i==0){
                first=currI;
            }
            if(i==size-1){
                last=currI;
            }
            if(node->left){
                q.push({node->left,currI*2+1});
            }
            if(node->right){
                q.push({node->right,currI*2+2});

        }
      
    }
    ans=max(ans,last-first+1);
  
}
return ans;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    cout<<width(root);

}