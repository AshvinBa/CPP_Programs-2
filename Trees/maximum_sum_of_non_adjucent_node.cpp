/*
Maximum sum of Non-adjacent nodes
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.
                                            
Example 1:
Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.

Example 2:
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
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

pair<int,int>solve(node* root)
    {
        if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
        }
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        
        pair<int,int>res;
        
        res.first= root->data + left.second + right.second;
        res.second=max(left.first,left.second)+max(right.first,right.second);
        
        return res;
    }
    
    int getMaxSum(node *root) 
    {
        pair<int,int>ans=solve(root);
        return max(ans.first,ans.second);
    }

int main(){
    node* root=NULL;
    root=buildtree(root);
    cout<<"The answer is: "<<getMaxSum(root);
return 0;
}
