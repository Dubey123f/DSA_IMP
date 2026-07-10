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
void levelorder(Node* root)
{
    // I need to print level by level means
    // 1
    // 2 3
    // 4 5
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    int sum=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
        sum+=curr->data;

        
    }
    cout << endl;
    cout<<"The sum of the level is: "<<sum<<endl;
    sum=0;
}

    

}
int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<"Level order Traversal of the tree is: "<<endl;
    levelorder(root);


   
}