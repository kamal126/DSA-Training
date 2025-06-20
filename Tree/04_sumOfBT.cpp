/* A binary tree node has data, pointer to left child
   and a pointer to right child*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Function to return a list containing the level order traversal in spiral form.


class Solution {
  public:
  void sumOf(Node *root, int& sum){
    if(!root)
        return;
    
    sum += root->data;
    sumOf(root->left,sum);
    sumOf(root->right,sum);
}
    int sumBT(Node* root) {
        // code here
        /* Approach 1 */
        // int sum = 0;
        // sumOf(root,sum);
        // return sum;
        
        /*Approach 2nd*/
        if(root==NULL)
            return 0;
        
        return (root->data + sumBT(root->left) + sumBT(root->right));
    }
};