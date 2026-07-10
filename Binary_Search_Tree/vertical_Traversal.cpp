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
//ek map banao jisme key column number hoga aur value ek map hoga 
//jisme key row number hoga aur value ek multiset hoga jisme us 
//column aur row pe jitne bhi nodes hai unke values honge
map<int,map<int,multiset<int>>>nodes;
void inorder(Node* root,int col,int row){
    if(root==nullptr){
        return;
    }
    inorder(root->left,col-1,row+1);
    //column aur row ke hisab se nodes ko map me insert karo
    //agar ek column aur row pe multiple nodes hai to
    // unko multiset me insert karo taki wo sorted order me rahe
    
    nodes[col][row].insert(root->data);
    inorder(root->right,col+1,row+1);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    inorder(root,0,0);
    //ab map me se vertical order traversal nikal ke ek 2D vector me store karo
    vector<vector<int>>res;
    //map me se vertical order traversal nikal ke ek 2D vector me store karo
    //nodes map me column ke hisab se sorted order me hai, to usko iterate karo
    for(auto &col:nodes){
        //ek temporary vector banao jisme current column ke nodes ke values honge
        vector<int>temp;
        //ab row ke hisab se sorted order me nodes ke values honge, to usko iterate karo
        for(auto &row:col.second){
            //ab multiset me se nodes ke values honge, to usko iterate karo
            //yha temp.end() se multiset ke values ko temp vector me insert kar rahe hai taki wo sorted order me rahe
            temp.insert(temp.end(),row.second.begin(),row.second.end());
        }
        res.push_back(temp);
    }
    cout<<"Vertical Traversal of Binary Tree: "<<endl;
    for(auto &v:res){
        for(auto &val:v){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}