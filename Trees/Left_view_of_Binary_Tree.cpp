/*
Left View of Binary Tree

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3

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

void left1(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    left1(root->left, ans, level + 1);
    left1(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    left1(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    vector<int> ans = leftView(root);
    cout << "The Left View is: ";
    cout << endl;
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}