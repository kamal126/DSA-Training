#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node *BST(Node *root, vector<int>arr, int idx){
    if(!root)
        return new Node(arr[idx++]);
    
    int node = arr[idx];
    if(node<root->data){
        root->left = BST(root->left, ) 
    }
    else {
        root->right = BST(root->right, arr[idx], idx);
    }

    return root;
}

void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int>arr = {10,2,5,17,8,12,23,13,15};
    Node *root = NULL;
    int idx = 0;

    root = BST(root,arr, idx);

    cout<<"Inorder Traversal: ";
    inorder(root);

    return 0;
}