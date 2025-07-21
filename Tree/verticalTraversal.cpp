#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};

// create BT
Node *BT(){
    int x;
    cin>>x;
    
    if(x==-1) return NULL;

    Node *tmp = new Node(x);

    cout<<"Enter left child of "<<tmp->data<<": ";
    tmp->left = BT();
    cout<<"enter right child of "<<tmp->data<<": ";
    tmp->right = BT();

    return tmp;
}

void inOrder(Node *root){
    if(!root) return;
    // left
    inOrder(root->left);
    // data
    cout<<root->data<<" ";
    // right
    inOrder(root->right);
}


void findMinMaxHD(Node *root, int pos, int &l, int &r){
    if(!root) return;

    l = min(l, pos);
    r = max(r, pos);

    findMinMaxHD(root->left, pos-1, l, r);
    findMinMaxHD(root->right, pos+1, l, r);
}

void veticalTraversal(Node *root, vector<vector<int>>ans){
    
    int l=0,r=0;

    vector<vector<int>>positive(r+1);
    vector<vector<int>>neg(abs(l)+1);

    queue<pair<Node*, int>>q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *tmp = q.front().first;
        int pos = q.front().second;
        q.pop();

        if(pos<0)
            neg[abs(pos)].push_back(tmp->data);
        else
            positive[pos].push_back(tmp->data);

        if(tmp->left){
            q.push({tmp->left, pos-1});
        }
        if(tmp->right){
            q.push({tmp->right, pos+1});
        }
    }

    vector<vector<int>>ans;

    for(int i=neg.size()-1; i>0;i--){
        ans.push_back(neg[i]);
    }

    for(int i=0;i<positive.size();i++){
        ans.push_back(positive[i]);
    }
    

    
}


int main(){
    
    int x;
    cout<<"enter root data: ";
    Node *root = BT();

    inOrder(root);




}