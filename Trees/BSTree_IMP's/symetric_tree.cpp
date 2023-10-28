/*
Symmetric Tree

Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:
Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric

Example 2:
Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: False
Your Task:
You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0<=Number of nodes<=100

*/

//{ Driver Code Starts
//Initial Template for C++


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
    // return true/false denoting whether the tree is Symmetric or not
    
    bool match(struct Node* temp1,struct Node* temp2)
    {
        if(temp1!=NULL && temp2!=NULL)
        {
            bool a=match(temp1->left,temp2->right);
            bool b=match(temp1->right,temp2->left);
            
            if((temp1->data == temp2->data) && a && b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(temp1==NULL && temp2==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    bool isSymmetric(struct Node* root)
    {
        bool val=match(root,root);
        
        return val;
    }
};


int main() {
    
        string s, ch;
        cout<<"Enter the values: ";
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    
    return 0;
}
