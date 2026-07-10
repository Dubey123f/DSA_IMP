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
void dfs(Node* root,int sum,int target,vector<int>&path,vector<vector<int>>&ans){
    if(root==nullptr){
        return;
    }
    sum+=root->data;
    path.push_back(root->data);
    if(root->left==nullptr && root->right==nullptr){
        if(sum==target){
            ans.push_back(path);
        }
        path.pop_back();
        return;
        
    }
    dfs(root->left,sum,target,path,ans);
    dfs(root->right,sum,target,path,ans);
    path.pop_back();

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<vector<int>>ans;
    vector<int>path;
    int sum=0;
    dfs(root,sum,5,path,ans);
    if(ans.size()==0){
        cout<<"No path found with the given sum"<<endl;
    }
    else{
        cout<<"All the paths from root to leaf with the given sum are: "<<endl;
        for(vector<int>v:ans){
            for(int i:v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}
