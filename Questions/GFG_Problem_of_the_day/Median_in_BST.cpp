/*
Median of BST

Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.

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

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

void inorder(Node* &root,vector<int>&arr)
{

    if(root==NULL)
    {
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

float findMedian(Node* root)
{
    vector<int>arr;
    inorder(root,arr);
    
    int n=arr.size();
    if(n%2==0)
    {
        int x=arr[n/2];
        int y=arr[n/2-1];
        return (float) (x+y)/2;
    }
    else
    {
        return (float) arr[n/2];
    }
    
}

Node* BuildTree(Node* &root)
{
    int val;
    cout<<"\nEnter the values: ";
    cin>>val;
    
    if(val==-1)
    {
        return NULL;
    }

    root=new Node(val);

    cout<<"Insert Data at Left of: "<<val<<endl;
    root->left=BuildTree(root->left);

    cout<<"Insert Data at Right of: "<<val<<endl;
    root->right=BuildTree(root->right);

    return root;
}

int main(){
    Node* root=NULL;
    
    BuildTree(root);
    cout<<"The Value of Median is: "<<findMedian(root);
return 0;
}