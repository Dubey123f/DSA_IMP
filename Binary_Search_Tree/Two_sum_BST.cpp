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
class BSTLeft{
    public:
    stack<Node*>st;
    BSTLeft(Node* root){
        pushAllleft(root);
    }
    void pushAllleft(Node* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    int next(){
        Node* temp=st.top();
        st.pop();
        pushAllleft(temp->right);
        return temp->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};
class BSTRight{
    public:
    stack<Node*>st;
    BSTRight(Node* root){
        pushAllright(root);
    }
    void pushAllright(Node* root){
        while(root!=NULL){
            st.push(root);
            root=root->right;
        }
    }
    int next(){
        Node* temp=st.top();
        st.pop();
        pushAllright(temp->left);
        return temp->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->right=new Node(7);
    int target=9;
    BSTLeft l(root);
    BSTRight r(root);
    int i=l.next();
    int j=r.next();
    while(i<j){
        if(i+j==target){
            cout<<"Pair found: "<<i<<" "<<j<<endl;
            return 0;
        }
        else if(i+j<target){
            i=l.next();
        }
        else{
            j=r.next();
        }
    }
}