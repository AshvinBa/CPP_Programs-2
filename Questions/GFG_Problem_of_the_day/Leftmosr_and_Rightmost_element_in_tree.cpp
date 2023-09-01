/*
Leftmost and rightmost nodes of binary tree
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:
Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7

Example 2:
Input:

        10
      /    \
     20     30
    / \  
   40  60
Output: 10 20 30 40 60
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

void printCorner(Node *root)
{
    queue<Node*>q;
    q.push(root);
    vector<vector<int>>ans;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            Node* frontNode=q.front();
            q.pop();
            
            if(frontNode->left)  //if left is exist then push in queue
            {
                q.push(frontNode->left);
            }
            if(frontNode->right)  //if right is exist then push in queue
            {
                q.push(frontNode->right);
            }
            level.push_back(frontNode->data);
        }
        ans.push_back(level);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].size()==1)
        {
            cout<<ans[i][0]<<" ";  //To print root node.
        }
        else
        {
            cout<<ans[i][0]<<" "<<ans[i][ans[i].size()-1]<<" ";  //To print first and last element.
        }
    }
    
}


int main()
{
    Node *root = NULL;
    buildTree(root);
    printCorner(root);
    return 0;
}