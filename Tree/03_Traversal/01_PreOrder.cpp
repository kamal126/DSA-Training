#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


Node* BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)
        return NULL;

    Node *temp = new Node(x);
    cout<<"Enter left node data of "<<x <<": ";
    temp->left = BinaryTree();
    cout<<"Enter right node data of "<<x<<": " ;
    temp->right = BinaryTree();

    return temp;
}


int main(){
    
    Node* root;
    cout<<"Enter root node: ";
    root = BinaryTree();


    preOrder(root);

    return 0;
}
