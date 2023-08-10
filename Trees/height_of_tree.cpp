/*
caluculate the height of tree.
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

int height(Node* root)
{
    if(root==NULL)
    return 0;

    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;
    return ans;
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
    cout<<"The Height of the root is: "<<height(root);    
return 0;
}


/*

Enter the data: 1
Insert at left of: 1
Enter the data: 2
Insert at left of: 2
Enter the data: 3
Insert at left of: 3
Enter the data: -1
Insert at right of: 3
Enter the data: -1
Insert at right of: 2
Enter the data: -1
Insert at right of: 1
Enter the data: 4
Insert at left of: 4
Enter the data: -1
Insert at right of: 4
Enter the data: 5
Insert at left of: 5
Enter the data: -1
Insert at right of: 5
Enter the data: -1
The Height of the root is: 3
*/