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
bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    return search(root->right,key);
}
int main(){
    Node* root=NULL;
    root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    if(search(root,3)){
        cout<<"Element found!"<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }

}