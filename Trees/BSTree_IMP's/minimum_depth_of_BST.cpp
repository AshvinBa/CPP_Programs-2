/*
Minimum Depth of a Binary Tree
Given a binary tree, find its minimum depth.

Example 1:
Input:
            1
          /   \
         3     2
        /
       4           

Output: 2
Explanation:
Minimum depth is between nodes 1 and 2 since
minimum depth is defined as  the number of 
nodes along the shortest path from the root 
node down to the nearest leaf node.

Example 2:
Input:
             10
          /     \
        20       30
          \        \   
          40        60 
                   /
                  2 
Output: 3
Explanation:
Minimum depth is between nodes 10,20 and 40.

Your Task:  
You don't need to read input or print anything. 
Complete the function minDepth() which takes the
root node as an input parameter and returns the
minimum depth.

Expected Time Complexity: O(N)

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        if(root==NULL)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        return 1;
        
        if(root->left==NULL)
        return 1+minDepth(root->right);
        
        if(root->right==NULL)
        return 1+minDepth(root->left);
        
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        
        int ans=min(l,r)+1;
        
        return ans;
    }
};
int main() {
    int t;
    string tc;
    cout<<"Enter the value of testcases: ";
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        // getline(cin, ch);
        Solution obj;
        cout << obj.minDepth(root) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}
