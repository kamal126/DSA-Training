#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Proper recursive binary tree construction from preorder with -1 as NULL
Node* BT(vector<int>& arr, int& idx) {
    if (idx >= arr.size() || arr[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(arr[idx++]);
    root->left = BT(arr, idx);
    root->right = BT(arr, idx);

    return root;
}

// Correct preorder traversal: Root → Left → Right
void preorder(Node *root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// Utility to print vector
void print(vector<int> arr) {
    for (auto &ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3,4,-1,-1,5,-1,-1,-1,6,7,-1,-1,8,-1,-1};
    int idx = 0;
    Node* root = BT(arr, idx);

    vector<int> ans;
    preorder(root, ans);

    cout << "PreOrder Traversal: ";
    print(ans);

    return 0;
}
