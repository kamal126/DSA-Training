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
    InOreder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node * root;
    cout<<"Enter the root Node: ";
    root = BinaryTree();
    
    cout<<"Post Order Travarsal: ";
    InOreder(root);
}

/**
Enter the root Node: 1
Enter the left node data of 1: 2
Enter the left node data of 2: 3
Enter the left node data of 3: 4
Enter the left node data of 4: -1
Enter the right node data of 4: 5
Enter the left node data of 5: -1
Enter the right node data of 5: -1
Enter the right node data of 3: 6
Enter the left node data of 6: -1
Enter the right node data of 6: -1
Enter the right node data of 2: 7
Enter the left node data of 7: 8
Enter the left node data of 8: -1
Enter the right node data of 8: -1
Enter the right node data of 7: -1
Enter the right node data of 1: 9
Enter the left node data of 9: 10
Enter the left node data of 10: -1
Enter the right node data of 10: 11
Enter the left node data of 11: -1
Enter the right node data of 11: -1
Enter the right node data of 9: 12
Enter the left node data of 12: -1
Enter the right node data of 12: -1
5 4 6 3 8 7 2 11 10 12 9 1 
 */