/*
Mirror Tree
EasyAccuracy: 72.67%Submissions: 156K+Points: 2
Done with this problem? Now use these skills to apply for a job in Job-A-Thon 21!

Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Example 1:
Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
Example 2:
Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
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
        left=NULL;
        right=NULL;
    }
};
void mirror(Node* &root)
{
    if(root==NULL)
    return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);   
}

void travers(Node* root)
{
    if(root==NULL)
    return;

    travers(root->left);
    cout<<root->data<<" ";
    travers(root->right);
}

Node* build_tree(Node* &root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }
    root=new Node(data);

    cout<<"Insert at Left of: "<<data<<endl;
    root->left=build_tree(root->left);

    cout<<"Insert at Right of: "<<data<<endl;
    root->right=build_tree(root->right);

    return root;
}

int main(){
    Node* root=NULL;
    build_tree(root);
    mirror(root);
    travers(root);
return 0;
}
