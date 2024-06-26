/*
K distance from root

Given a binary tree having n nodes and an integer k. Print all nodes 
that are at distance k from the root (root is considered at distance 
0 from itself). Nodes should be printed from left to right.

Example 1:
Input:
k = 0
      1
    /   \
   3     2
Output: 
1
Explanation: 
1 is the only node which is 0 distance from the root 1.

Example 2:
Input:
k = 3
        1
       /
      2
       \
        1
      /  \
     5    3
Output: 
5 3
Explanation:  
5 and 3 are the nodes which are at distance 3 from the root 3.
Here, returning 3 5 will be incorrect.
Your Task:
You don't have to take input. Complete the function Kdistance() 
that accepts root node and k as parameters and returns the value 
of the nodes that are at a distance k from the root.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 104
0 <= k <= 30
*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution
{
    public:
    // function should print the nodes at k distance from root
    void traverse(struct Node *root, int k, vector<int>&mp)
    {
        if(root==NULL)
        return;
        
        if(k==0)
        mp.push_back(root->data);
        else
        {
            traverse(root->left, k-1, mp);
            traverse(root->right, k-1, mp);
        }
        
    } 
    
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int>mp;
        traverse(root,k,mp);
        return mp;
    }  
};

int main()
{

    int t;
    cout<<"Number of test cases: ";
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        cout<<"Enter the values of K: ";
		scanf("%d ",&k);
        string s;
        cout<<"Enter the values: ";
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> vec = obj.Kdistance(root, k);
        cout<<"Answer: ";
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}