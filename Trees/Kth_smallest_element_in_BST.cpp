/*
k-th smallest element in BST
Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 

Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2
Explanation: 2 is the 2nd smallest element in the BST

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and returns the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=10^5
*/

#include <bits/stdc++.h>
using namespace std;

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

int inorder(Node* root,int &i,int k)
    {
        if(root==NULL)
        return -1;
        
        
        int left=inorder(root->left,i,k);
        if(left!=-1)
        return left;
        
        i++;
        
        if(i==k)
        return root->data;
        
        return inorder(root->right,i,k);
        
    }
    
    
    int KthSmallestElement(Node *root, int K) {
        int i=0;
        int n=inorder(root,i,K);
        return n;
    }

int main()
{
    cout<<"Enter the values: ";
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        cout<<"Enter the k: ";
        int k;
        cin>>k;
        getchar();        
        cout << KthSmallestElement( head, k ) << endl;
    
    return 1;
}






