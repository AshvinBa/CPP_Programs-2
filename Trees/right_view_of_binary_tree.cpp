/*
Right View of Binary Tree

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

      1
     /  \
    2    3
   / \   / \
  4   5 6   7
   \
    8

Example 1:
Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:
Input:
     10
    /   \
  20     30
 /   \
40  60
Output: 10 30 60

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

void Right_tra(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    Right_tra(root->right, ans, level + 1);
    Right_tra(root->left, ans, level + 1);
}

vector<int> RightView(Node *root)
{
    vector<int> ans;
    Right_tra(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    vector<int> ans = RightView(root);
    cout << "The Right View is: ";
    cout << endl;
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}