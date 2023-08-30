/*
Diagonal Traversal of Binary Tree

Given a Binary Tree, print the diagonal traversal of the binary tree.
Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

Example 1:
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
*/
#include <iostream>
#include <bits/stdc++.h>
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


vector<int> diagonal(Node *root)
{
    queue<Node*>q;
    vector<int>ans;

    if(root==NULL)
    return ans;

    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        while(temp!=NULL)
        {
            if(temp->left)
            q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
return ans;
}


int main()
{
    Node *root = NULL;
    buildTree(root);
    vector<int> ans = diagonal(root);
    cout << "The Top View is: ";
    cout << endl;
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
