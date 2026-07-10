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
Node* insertbst(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
      root->left= insertbst(root->left,val);

    }
    else{
        root->right= insertbst(root->right,val);
    }
return root;
}
void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    int val;
    cout<<"Enter the value to insert: ";
    cin>>val;
 insertbst(root,val);
    cout<<"Value inserted successfully"<<endl;
    cout<<"The tree looks like: "<<endl;
    print(root);
}
