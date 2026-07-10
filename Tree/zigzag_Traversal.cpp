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
vector<vector<int>>bfs(Node* root){
    vector<vector<int>>ans;
    if(root==nullptr){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    bool left_to_right=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            if(left_to_right){
                level[i]=node->data;
            }
            else{
                level[size-1-i]=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        ans.push_back(level);
        left_to_right=!left_to_right;
    }
    return ans;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    vector<vector<int>>ans=bfs(root);
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }

}