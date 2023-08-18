/*
Sum Tree

Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Example 1:
Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

Example 2:
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation:
The given tree is not a sum tree.
For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.

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


pair<bool,int>isSumTreeFast(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL  && root->right==NULL)
        {
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int>leftAns=isSumTreeFast(root->left);
        pair<bool,int>rightAns=isSumTreeFast(root->right);
        
        bool isLeftSumTree=leftAns.first;
        bool isRightSumTree=rightAns.first;
        
        int leftSum=leftAns.second;
        int RightSum=rightAns.second;
        
        bool cond = root->data == leftSum + RightSum;
        pair<bool,int>ans;
        
        if(isLeftSumTree && isRightSumTree && cond)
        {
            ans.first=true;
            ans.second=root->data+leftSum + RightSum;
        }
        else
        {
            ans.first=false;
        }
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
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

    if(isSumTree(root))
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }

return 0;
}
