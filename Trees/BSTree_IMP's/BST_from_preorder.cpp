//Binary Search Tree from Preorder.

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

void inOrder(Node* root,vector<int>&ans)
{
    if(root==NULL)
    return;

    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

Node* solve(vector<int>ans,int mini,int maxi,int i)
{
    if(i >= ans.size())
    return NULL;

    if(ans[i] < mini || ans[i] > maxi)
    return NULL;

    Node* root=new Node(ans[i++]);
    root->left = solve(ans,mini,root->data,i);
    root->right = solve(ans,root->data,maxi,i);

    return root;
}
Node* preOrderToBST(vector<int>&ans)
{
    int maxi=INT16_MAX;
    int mini=INT16_MIN;    
    int i=0;
    return solve(ans,mini,maxi,i);
}

void print(Node* root)
{
    if(root==NULL)
    return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    vector<int>ans;
    takeInput(root);
    inOrder(root,ans);
    print(root);
return 0;
}

