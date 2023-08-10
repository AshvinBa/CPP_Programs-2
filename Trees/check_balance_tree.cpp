/*
check the tree is balance or not

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int f=1;
int solve(Node* root)
{
    if(root==NULL)
    return 0;

    int left=solve(root->left);
    int right=solve(root->right);

    if(abs(left-right)>1)return f=0;

    return max(left,right)+1;
}

bool balance(Node* root)
{
    f=1;
    solve(root);
    return f;
}


Node* buildTree(Node* &root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }

    root=new Node(data);

    cout<<"Insert at left of: "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Insert at right of: "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

int main(){

    Node* root=NULL;

    buildTree(root);

    if(balance(root))
    {
        cout<<"Yes the tree is balance."<<endl;
    }
    else
    {
        cout<<"The Tree is not balance."<<endl;
    }
return 0;
}
