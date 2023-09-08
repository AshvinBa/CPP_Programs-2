/*
Sum of nodes on the longest path from root to leaf node
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13

Example 2:
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11

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

void solve(Node* root,int sum,int &maxSum,int len,int &maxLen)
    {
        if(root==NULL)
        {
            if(len>maxLen)
            {
                maxLen=len;
                maxSum=sum;
            }
            else if(len==maxLen)
            {
                maxSum=max(sum,maxSum);
            }
            return;
        }
        
        sum=sum+root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len=0;
        int maxLen=0;
        int sum=0;
        int maxSum=INT_MIN;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
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
    Node *root1 = NULL;
    cout<<"\nEnter for First Tree.";
    buildTree(root1);
    cout<<"The Sum of Longest Path of The Tree: "<<sumOfLongRootToLeafPath(root);
    return 0;
}