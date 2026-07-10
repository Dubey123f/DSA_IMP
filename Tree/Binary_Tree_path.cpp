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
void dfs(Node* root,string path,vector<string>&ans){
    if(root==nullptr){
        return;
    }
    if(path.size()==0){
        path+=to_string(root->data);
    }
    else{
        path+="->"+to_string(root->data);
    }
   
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(path);
    }
    dfs(root->left,path,ans);
    dfs(root->right,path,ans);
    
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<string>ans;
    string path="";
    dfs(root,path,ans);
    cout<<"All the paths from root to leaf are: "<<endl;
    for(string s:ans){
        cout<<s<<endl;
    }

}