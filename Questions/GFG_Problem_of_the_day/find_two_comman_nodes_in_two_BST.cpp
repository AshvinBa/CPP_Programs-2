/*
Find the comman nodes in two BST.
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.
Note: Return the common nodes in sorted order.

Example 1:
Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10

Example 2:
Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3

Your Task:
You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

Constraints:
1 <= Number of Nodes <= 105
1 <= Node data <= 109

*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
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
    //Function to find the nodes that are common in both BST. 
    void inorder(Node *root , map<int,int>&mp)
    {
        if(root==NULL)
        return;
        
        inorder(root->left,mp);
        mp[root->data]++;
        inorder(root->right,mp);
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>a1;
        // vector<int>a2;
        map<int,int>mp;
        
        inorder(root1,mp);
        inorder(root2,mp);
        
        for(auto i:mp)
        {
            if(i.second>1)
            {
                a1.push_back(i.first);
            }
        }
        return a1;
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        cout<<"Enter the values of first BST: ";
        getline(cin,s);
        Node* root1 = buildTree(s);
        cout<<"Enter the values of second BST: ";
        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }
	return 1;
}