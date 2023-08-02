#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    stack<Node *> s;
    Node *T = root;

    while (T != NULL)
    {
        s.push(T);
        T = T->left;
    }
    while (!s.empty())
    {
        T = s.top();
        s.pop();
        cout << T->data << " ";
        T = T->right;
        while (T != NULL)
        {
            s.push(T);
            T = T->left;
        }
    }
}

Node *Build_Tree(Node *&root)
{
    int val;
    cout << "Enter the data: ";
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    root = new Node(val);

    cout << "Insert at left of: " << val << endl;
    root->left = Build_Tree(root->left);

    cout << "Insert at right of: " << val << endl;
    root->right = Build_Tree(root->right);

    return root;
}

int main()
{
    Node *root;
    Build_Tree(root);
    cout << "InOrder Traversal: ";
    inorder(root);
    return 0;
}
