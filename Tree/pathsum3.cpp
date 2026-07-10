// we need to count the paths that sum to a given value in a binary tree. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

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
int main(){

}