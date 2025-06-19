#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left node data of "<<x<<": ";
    temp->left = BinaryTree();
    cout<<"Enter the right node data of "<<x<<": ";
    temp->right = BinaryTree();

    return temp;
};

void InOreder(Node *root){
    if(root==NULL)
        return;
    
    InOreder(root->left);
    cout<<root->data<<" ";
    InOreder(root->right);
}

int main(){
    Node * root;
    cout<<"Enter the root Node: ";
    root = BinaryTree();

    InOreder(root);
}