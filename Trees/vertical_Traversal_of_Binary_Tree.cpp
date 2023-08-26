/*
Vertical Traversal of Binary Tree.

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:
Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6

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

vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>>nodes;
        
        queue<pair<Node*,pair<int,int>>>q;
        
        vector<int>ans;
        
        if(root==NULL)
        return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty())
        {
            pair<Node*,pair<int,int>>temp=q.front();
            
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            
            if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            
        }
        
        for(auto i:nodes)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
}

int main()
{

    Node *root = NULL;
    cout<<"Impliment Tree: "<<endl;
    buildTree(root);
    vector<int>ans= verticalOrder(root);
    cout<<"\nAnswer: ";
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
