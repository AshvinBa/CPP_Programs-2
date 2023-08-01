#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{ 
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

void inorder(Node* root,vector<int>&arr)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

int inorderSucc(Node* root, Node* x)
{
    vector<int>arr;
    inorder(root,arr);
    int k=x->data;
    int ans;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==k)
        {
            ans=arr[i+1];
            return ans;
        }
    }
    // Node* val=new Node(ans);
    // return val;
}

Node* buildNode(Node* &root)
{
    int val;
    cout<<"Enter the Data: ";
    cin>>val;

    if(val==-1)
    {
        return NULL;
    }
    root=new Node(val);

    cout<<"Insert at Left of: "<<val<<endl;
    root->left=buildNode(root->left);

    cout<<"Insert at Right of: "<<val<<endl;
    root->right=buildNode(root->right);

    return root;
}


int main(){
    Node* root=NULL;
    Node* x=new Node(8);
    
    buildNode(root);
    Node* ans=new Node(inorderSucc(root,x));
    cout<<"\nAnswer: "<<ans->data;
return 0;
}