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
Node* buildTree(vector<int>&preOrder,vector<int>&inOrder,int& preIndex,int instart,int inEnd){
    //check karo ki preIndex out of bound to nahi hai aur instart greater than inEnd to nahi hai
    if(instart>inEnd){
        return nullptr;
    }
    // root value preOrder ke current index pe hoga
    int rootVal=preOrder[preIndex++];
    // root node banao
    Node* root=new Node(rootVal);
    // find the index of root value in inOrder array
    int inIndex=-1;
    // inOrder array me root value ka index dhundo
    for(int i=instart;i<=inEnd;i++){
        if(inOrder[i]==rootVal){
            inIndex=i;
            break;
        }
    }
    // ab left subtree ke liye recursive call karo aur right subtree ke liye bhi recursive call karo
    root->left=buildTree(preOrder,inOrder,preIndex,instart,inIndex-1);
    // right subtree ke liye recursive call
    root->right=buildTree(preOrder,inOrder,preIndex,inIndex+1,inEnd);
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
    vector<int> preOrder={3,9,20,15,7};
    vector<int> inOrder={9,3,15,20,7};
    int preIndex=0;
    Node* root=buildTree(preOrder,inOrder,preIndex,0,inOrder.size()-1);
    printPretty(root);

    return 0;
}