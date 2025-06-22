#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left=right=NULL;
    }
};

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

int countNonLeaf(Node *root){
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL)
        return 0;
    
    return 1 + countNonLeaf(root->left) + countNonLeaf( root->right);
}

int main(){
     Node* root;
    cout<<"Enter root node: ";
    root = BinaryTree();

    cout<<countNonLeaf(root);

    return 0;
    
}