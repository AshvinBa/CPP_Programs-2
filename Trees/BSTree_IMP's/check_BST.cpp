/*
Check BST(Binary Search Tree.)
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

vector<int> inOrder(Node* root)
{
    vector<int>ans;

    if(root==NULL)
    return ans;

    inOrder(root->left);
    ans.push_back(root->data);
    inOrder(root->right);
}

bool isBST(vector<int>ans)
{
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>ans[i+1])
        return false;
    }
    return true;
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


int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    vector<int>ans=inOrder(root);    

    if(isBST(ans))
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}