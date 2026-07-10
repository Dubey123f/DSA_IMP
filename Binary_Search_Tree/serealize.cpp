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

void serialize(Node* root,vector<string>&res){
    if(root==nullptr){
        res.push_back("null");
        return;
    }
    res.push_back(to_string(root->data));
    serialize(root->left,res);
    serialize(root->right,res);
}
Node* deserialize(vector<string>& res,int& index){
    if(index>=res.size()|| res[index]=="null"){
        index++;
        return nullptr;
    }
    Node* root=new Node(stoi(res[index++]));
    root->left=deserialize(res,index);
    root->right=deserialize(res,index);
    return root;
}
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void fill(vector<vector<string>>& res, Node* root, int row, int l, int r) {
    if (!root || l > r) return;

    int mid = (l + r) / 2;
    res[row][mid] = to_string(root->data);

    fill(res, root->left, row + 1, l, mid - 1);
    fill(res, root->right, row + 1, mid + 1, r);
}

void printPretty(Node* root) {
    int h = height(root);
    int w = pow(2, h) - 1;

    vector<vector<string>> res(h, vector<string>(w, " "));

    fill(res, root, 0, 0, w - 1);

    for (auto &row : res) {
        for (auto &cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    vector<string> res;
    serialize(root,res);
    cout<<"Serialized Tree: ";
    for(auto &s:res){
        cout<<s<<" ";
    }
    cout<<endl;
    int index=0;
    Node* deserializedRoot=deserialize(res,index);
    cout<<"Deserialized Tree: "<<endl;
    printPretty(deserializedRoot);
    
    return 0;
}