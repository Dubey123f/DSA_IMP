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
int i=0;
Node* buildTree(vector<int>& preorder,int bound){
 if(i==preorder.size()|| preorder[i]>bound){
    return nullptr;
 }
 Node* root=new Node(preorder[i++]);
 root->left=buildTree(preorder,root->data);
 root->right=buildTree(preorder,bound);
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
    vector<int> preorder={8,5,1,7,10,12};
    Node* root=buildTree(preorder,INT_MAX);
    printPretty(root);

    return 0;

}