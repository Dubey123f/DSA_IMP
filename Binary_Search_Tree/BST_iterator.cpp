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
class BSTIterator{
    public:
    stack<Node*>st;
    BSTIterator(Node* root){
        pushALL(root);

    }
    void pushALL(Node* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    int next(){
        Node* temp=st.top();
        st.pop();
        pushALL(temp->right);
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
    BSTIterator* obj=new BSTIterator(root);
    cout<<"Next element in BST is: "<<obj->next()<<endl;
    cout<<"Next element in BST is: "<<obj->next()<<endl;
    cout<<"Next element in BST is: "<<obj->next()<<endl;
    cout<<"Next element in BST is: "<<obj->next()<<endl;
    cout<<"Has next element in BST: "<<obj->hasNext()<<endl;
    cout<<"Has next element in BST: "<<obj->hasNext()<<endl;
    

}