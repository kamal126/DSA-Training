#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

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


int main(){
    
    Node* root;
    cout<<"Enter root node: ";
    root = BinaryTree();

    return 0;
}