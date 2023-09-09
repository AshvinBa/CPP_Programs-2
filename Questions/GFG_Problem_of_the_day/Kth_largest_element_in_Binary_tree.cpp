/*
Kth largest element in BST
Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:
Input:
       9
        \ 
          10
K = 1
Output: 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

Constraints:
1 <= N <= 105
1 <= K <= N
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
    int reverseOrder(Node* root,int &i,int k)
    {
        if(root==NULL)
        return -1;
        
        int right=reverseOrder(root->right,i,k);
        if(right!=-1)
        return right;
        
        i++;
        
        if(i==k)
        return root->data;
        
        return reverseOrder(root->left,i,k);
        
    }
    
    int kthLargest(Node *root, int k)

    {
        int i=0;
        int n=reverseOrder(root,i,k);
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
        
        cout << kthLargest( head, k ) << endl;
    
    return 1;
}