/*
Determine if Two Trees are Identical

Given two binary trees, the task is to find if both of them are identical or not. 
Example 1:
Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.

Example 2:
Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: No
Explanation: There are two trees both
having 3 nodes and 2 edges, but both
trees are not identical.

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

bool identical(Node* root1,Node* root2)
{
    if(root1==NULL and root2==NULL)
    {
        return true;
    }

    if(root1==NULL and root2!=NULL)
    {
        return false;
    }

    if(root1!=NULL and root2==NULL)
    {
        return false;
    }
    
    bool left=identical(root1->left,root2->left);
    bool right=identical(root1->right,root2->right);

    bool value=root1->data==root2->data;

    if(left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }  

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
    Node *root2 = NULL;
    cout<<"Impliment first Tree: "<<endl;
    buildTree(root1);
    cout<<"Imoliment Second Tree: "<<endl;
    buildTree(root2);
    if(identical(root1,root2))
    {
        cout<<"Similar.";
    }
    else
    {
        cout<<"Not Similar.";
    }
    return 0;
}
