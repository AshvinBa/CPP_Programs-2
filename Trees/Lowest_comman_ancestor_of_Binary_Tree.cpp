/*
Lowest Common Ancestor in a Binary Tree
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:
Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.

Example 2:
Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
        return NULL;
        
        if(root->data==n1 || root->data==n2)
        return root;
        
        Node* leftNode=lca(root->left,n1,n2);
        Node* rightNode=lca(root->right,n1,n2);
        
        if(leftNode!=NULL && rightNode!=NULL)
        {
            return root;
        }
        else if(leftNode==NULL && rightNode!=NULL)
        {
            return rightNode;
        }
        else if(leftNode!=NULL && rightNode==NULL)
        {
            return leftNode;
        }
        else
        {
            return NULL;
        }
    }
    
Node *buildTree(Node *&root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Insert at left of: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Insert at right of: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    Node *root = NULL;
    cout<<"\nEnter for First Tree.";
    buildTree(root);
    int n1,n2;
    cout<<"Enter the values of n1 and n2: ";
    cin>>n1>>n2;
    cout<<"The Lowest Comman Ancestor: "<<lca(root,n1,n2)->data;
    return 0;
}