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
Node* deleteNode(Node* root,int key){
    //check karega ki root null to nahi hai
    if(root==NULL){
        return root;
    }
    // agar key root ke data se chhota hai to left subtree me jao
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    // agar key root ke data se bada hai to right subtree me jao
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    // agar key root ke data ke barabar hai to delete karna hai
    else{
        // case 1: agar root ke left child null hai to right child ko return karo
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        // case 2: agar root ke right child null hai to left child ko return karo
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        // case 3: agar root ke dono child exist karte hai to inorder successor ko find karo
        // inorder successor find karne ke liye right subtree me jao aur leftmost node ko find karo
        // inorder successor ko find karne ke baad root ke data ko inorder successor ke data se replace karo
        //temp variable me root ke right child ko store karo aur uske leftmost node ko find karo
        Node* temp=root->right;
        //jab tak temp ke left child null nahi hai tab tak temp ko left child me move karo
        while(temp->left!=NULL){
            //temp ko left child me move karo
            temp=temp->left;
        }
        //root ke data ko temp ke data se replace karo
        root->data=temp->data;
        //ab temp ke data ko delete karna hai to right subtree me jao aur temp ke data ko delete karo
        root->right=deleteNode(root->right,temp->data);
    }
    //ab root ko return karo
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->right=new Node(7);
    int key=3;
    root=deleteNode(root,key);
    cout<<"Now the  tree after deleting "<<key<<" looks like: "<<endl;
    inorder(root);
    
    return 0;

}