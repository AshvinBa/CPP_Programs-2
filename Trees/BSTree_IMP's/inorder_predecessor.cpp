
/*






**********************************************************
Not Run.






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

void inOrder(Node* root)
{
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

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

Node* predecessor(Node* root,int val)
{
    Node* temp=root;
    if(root==NULL)
    {
        return NULL;
    }

    predecessor(root->left,val);
    Node* prev=temp;
    if(temp->left->data == val || temp->right->data == val)
    {
        return prev;
    }
    predecessor(root->right,val);
}

int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    inOrder(root);    
    int val;
    cout<<endl;
    cout<<"Enter the values: ";
    cin>>val;
    Node * temp=predecessor(root,val);
    cout<<"Answer: "<<temp->data<<" ";
return 0;
}
