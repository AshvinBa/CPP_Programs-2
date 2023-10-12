//Two sum in BST.

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

void findPair(Node* root,vector<int>&arr)
{
    if(root==NULL)
    {
        return;
    }

    findPair(root->left,arr);
    arr.push_back(root->data);
    findPair(root->right,arr);
}

bool isIt(vector<int>arr,int x)
{
    int i=0;
    int j=arr.size();

    while(i<j)
    {
        if((arr[i]+arr[j])==x)
        {
            return 1;
        }
        else if((arr[i]+arr[j])<x)
        {
            i++;
        }
        else if((arr[i]+arr[j])>x)
        {
            j--;
        }
    }
    return 0;
}

int main(){
    Node* root=NULL;
    cout<<"Enter the values: ";
    takeInput(root);
    int x;
    cout<<"Enter the x: ";
    cin>>x;
    vector<int>arr;
    findPair(root,arr);
    if(isIt(arr,x)>0)
    {
        cout<<"Yes";
    }  
    else
    {
        cout<<"No";
    }
return 0;
}

