#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to build the binary tree
Node* BinaryTree() {
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);
    cout << "Enter left node data of " << x << ": ";
    temp->left = BinaryTree();
    cout << "Enter right node data of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

// Function to compute the size (number of nodes)
int countleavesNodes(Node* root) {
    if (root == NULL)
        return 0;
    
    if(root->left==NULL && root->right== NULL)
        return 1;
    
    return  countleavesNodes(root->left)+leavesNodes(root->right);
}

int main() {
    cout << "Enter root node: ";
    Node* root = BinaryTree();

    int totalNodes = countleavesNodes(root);
    cout << "Number of leaf nodes in the binary tree: " << totalNodes << endl;

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
Leaves of the binary tree (number of nodes): 5
 */