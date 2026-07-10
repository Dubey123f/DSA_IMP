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
bool searchBT(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    else if(key<root->data){
        return searchBT(root->left,key);
    }
    else{
        return searchBT(root->right,key);
    }

}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    if(searchBT(root,key)){
        cout<<"Key found in the BST"<<endl;
    }
    else{
        cout<<"Key not found in the BST"<<endl;
    }
}
