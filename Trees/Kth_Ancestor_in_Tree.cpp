/*
Kth Ancestor in a Tree
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Example 1:
Input:
K = 2 Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.

Example 2:
Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.
Your Task:
You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input parameters, and returns the kth ancestor of Node which contains node as its value.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=105
1<= K <= 100
1 <= Node.data <= N



*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node* root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root=new node(data);

    cout<<"Enter the data for inserting at left of: "<<data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter the data for inserting at right of: "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}


node* solve(node* root,int &k,int node)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==node)
    {
        return root;
    }
    
    node* leftnode=solve(root->left,k,node);
    node* rightnode=solve(root->right,k,node);
    
    if(leftnode!=NULL && rightnode==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return leftnode;
    }
    
    if(leftnode==NULL && rightnode!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightnode;
    }
    
    return NULL;
}

int kthAncestor(node *root, int k, int node)
{
    node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}


int main(){
    node* root=NULL;
    root=buildtree(root);
return 0;
}