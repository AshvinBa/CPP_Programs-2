/*
Delete Node in BST.
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

Node* minVal(Node* root)
{
    Node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root,int val)
{
    //base case
    if(root==NULL)
    {
        return root;
    }

    if(root->data == val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left !=NULL && root->right !=NULL )
        {
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val)
    {  
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else
    {
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    cout<<"TnOrder Traversal of The Tree: ";
    inOrder(root);    
    int val;
    cout<<endl;
    cout<<"Enter the value to be delete: ";
    cin>>val;
    Node* temp=deleteFromBST(root,val);
    
    cout<<"The deleted element is: "<<val<<endl;
    cout<<"After deleting the Element: "<<endl;
    inOrder(root);
return 0;
}
