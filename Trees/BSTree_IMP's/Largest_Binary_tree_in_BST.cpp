/*
Largest BST
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.

Example 2:
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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
    int maxi;
    int mini;
    bool isBST;
    int size;
    
    
    Solution solve(Node *root,int &ans)
    {
        if(root==NULL)
        {
            return {INT_MIN,INT_MAX,true,0};
        }
        
        Solution left=solve(root->left,ans);
        Solution right=solve(root->right,ans);
        
        Solution currNode;
        
        currNode.size=left.size+right.size+1;
        currNode.maxi=max(root->data,right.maxi);
        currNode.mini=min(root->data,left.mini);
        
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        {
            currNode.isBST=true;
        }
        else
        {
            currNode.isBST=false;
        }
        if(currNode.isBST)
        {
            ans=max(ans,currNode.size);
        }
        
        return currNode;
    }
    
    int largestBst(Node *root)
    {
    	int maxSize=0;
    	Solution temp=solve(root,maxSize);
    	return maxSize;
    }
};

int main() {   
    int t;
    cout<<"Enter the number of test cases: ";
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        cout<<"Enter the value of tree: ";
        getline(cin, s);     
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}