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
int size(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int main() {
    cout << "Enter root node: ";
    Node* root = BinaryTree();

    int totalNodes = size(root);
    cout << "Size of the binary tree (number of nodes): " << totalNodes << endl;

    return 0;
}
