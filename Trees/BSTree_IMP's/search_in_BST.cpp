/*
Search Element in BST.
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
//Approach - 2.
bool search(Node *root,int x)
{
    Node* temp=root;

    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            return true;
        }

        if(temp->data > x)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return false;
}

int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    int x;
    cout<<"Enter the x: ";
    cin>>x;
    if(search(root,x))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
return 0;
}


/*

Approach -1.

bool search(Node* root,int x)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==x)
    {
        return true;
    }
    
    if(root->data > x)
    {
        return search(root->left,x);
    }
    else
    {
        return search(root->right,x);
    }
}


*/