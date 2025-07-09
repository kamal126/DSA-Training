#include<bits/stdc++.h>
using namespace std;


struct Node{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

void find(struct Node *root, vector<int>&arr){
    if(!root) return;

    find(root->left, arr);
    arr.push_back(root->data);
    find(root->right, arr);
}

float median(struct Node *root){
    vector<int>arr;
    find(root, arr);

    int n = arr.size();

    if(n%2==0) 
        return (arr[n/2 -1] + arr[n/2])/2.0;
    else
        return arr[n/2];
}

