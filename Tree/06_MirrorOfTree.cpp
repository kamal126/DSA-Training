#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node *BinaryTree(){
    int x;
    cin>>x;

    if(x==-1) return NULL;

    Node *temp = new Node(x);
    cout<<"enter left node of "<<x<<": ";
    temp->left = BinaryTree();
    cout<<"enter right node of "<<x<<": ";
    temp->right = BinaryTree();
    
}
void mirror(){}


int main(){

}