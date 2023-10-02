/*
Maximum value in BST
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node
{
    public: 

    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertIntoTree(Node *root,int d)
{
    if(root==NULL)
    {
        root=new Node(d);
        return root;
    }

    if( d > root->data )
    {
        root->right=insertIntoTree(root->right,d);
    }
    else
    {
        root->left=insertIntoTree(root->left,d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root=insertIntoTree(root,data);
        cin>>data;
    }
}

Node *maxVal(Node* root)
{
    Node* temp=root;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    cout<<"Largest value in Tree: "<<maxVal(root)->data;
return 0;
}
