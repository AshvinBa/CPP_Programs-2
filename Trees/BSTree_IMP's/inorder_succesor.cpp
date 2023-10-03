/*
Inorder Successor.
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

void inOrder(Node* root,vector<int>&ans)
{
    if(root==NULL)
    return;

    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
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

int Successor(Node* root,int val)
{
    vector<int>ans;
    inOrder(root,ans);

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==val)
        {
            return ans[i+1];
        }
    }
    return -1;
}

int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);    
    int val;
    cout<<endl;
    cout<<"Enter the values: ";
    cin>>val;
    cout<<"Answer: "<<Successor(root,val)<<" ";
return 0;
}
