#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

// L -> lowerbond, U - upperbond
Node *BST(vector<int>&preorder,int &idx, int L, int U){
    if(idx>=preorder.size() || preorder[idx]<L || preorder[idx]>U)
        return NULL;

    Node *root = new Node(preorder[idx++]);

    root->left = BST(preorder, idx, L, root->data);
    root->right = BST(preorder, idx, root->data, U);
}

Node *preorderToBST(vector<int>&preorder){
    int idx = 0;
    return BST(preorder, idx, INT_MIN, INT_MAX);
}

void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

int main(){
    vector<int>preorder = {8,5,1,7,10,12};

    Node *root = preorderToBST(preorder);

    cout<<"inorder traversal: ";
    inorder(root);

    return 0;
}