/*
Diameter of a Binary Tree

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Example 1:
Input:
       1
     /  \
    2    3
Output: 3

Example 2:
Input:
         10
        /   \
      20    30
    /   \
   40   60
Output: 4

*/
#include<iostream>
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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    int l = height(root->left);
    int r = height(root->right);

    ans = max(l, r) + 1;
    return ans;
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    int A1 = diameter(root->left);
    int A2 = diameter(root->right);
    int A3 = height(root->left) + height(root->right) + 1;
    ans = max(A1, max(A2, A3));

    return ans;
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

    buildTree(root);
    cout << "\nAnswer: " << diameter(root);
    return 0;
}
