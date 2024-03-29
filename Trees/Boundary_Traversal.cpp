/*
Boundary Traversal of binary tree

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:
Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:

Example 2:
Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
Explanation:
As you can see we have not taken the right subtree. 


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

void traversaLeft(Node* root,vector<int>&ans)
{
    if((root==NULL)||(root->left==NULL && root->right==NULL))
    return;

    ans.push_back(root->data);

    if(root->left)
    traversaLeft(root->left,ans);
    else
    traversaLeft(root->right,ans);
}

void traversLeaf(Node* root,vector<int>&ans)
{
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traversLeaf(root->left,ans);

    traversLeaf(root->right,ans);
}

void traversaRight(Node* root,vector<int>&ans)
{
    if((root==NULL)||(root->left==NULL && root->right==NULL))
    return;

    if(root->right)
    traversaLeft(root->right,ans);
    else
    traversaLeft(root->left,ans);

    ans.push_back(root->data);
}

vector<int>boundary(Node* root)
{
    vector<int>ans;

    if(root==NULL)
    return ans;

    ans.push_back(root->data);

    traversaLeft(root->left,ans);

    traversLeaf(root->left,ans);
    traversLeaf(root->right,ans);

    traversaRight(root->right,ans);

    return ans;
}

int main()
{

    Node *root = NULL;
    cout<<"Impliment Tree: "<<endl;
    buildTree(root);
    vector<int>ans= boundary(root);
    cout<<"\nAnswer: ";
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
