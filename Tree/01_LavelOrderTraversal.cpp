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

void levelOrderTravarsal(Node *root){
    if(root==NULL) 
        return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->left;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
}

int main(){
    
    Node* root;
    cout<<"Enter root node: ";
    root = BinaryTree();
    
    queue<Node*>q;
    q.push(root);

    cout<<"Level Order Travarsal: ";
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }

    // levelOrderTravarsal(root);
    return 0;
}

/**
Enter root node: 1
Enter left node data of 1: 2
Enter left node data of 2: 3
Enter left node data of 3: 4
Enter left node data of 4: -1
Enter right node data of 4: 5
Enter left node data of 5: -1
Enter right node data of 5: -1
Enter right node data of 3: 6
Enter left node data of 6: -1
Enter right node data of 6: -1
Enter right node data of 2: 7
Enter left node data of 7: 8
Enter left node data of 8: -1
Enter right node data of 8: -1
Enter right node data of 7: -1
Enter right node data of 1: 9
Enter left node data of 9: 10
Enter left node data of 10: -1
Enter right node data of 10: 11
Enter left node data of 11: -1
Enter right node data of 11: -1
Enter right node data of 9: 12
Enter left node data of 12: -1
Enter right node data of 12: -1
Level Order Travarsal: 1 2 9 3 7 10 12 4 6 8 11 5 
 */