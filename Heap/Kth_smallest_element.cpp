/*
Is Binary Tree Heap

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000


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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
class Solution {
  public:
    
    int countNodes(struct Node* tree)
    {
        if(tree==NULL)
        return 0;
        
        int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
        
        return ans;
    }
  
    bool isCBT(struct Node* root,int index,int cnt)
    {
        if(root==NULL)
        return true;
        
        if(index>=cnt)
        return false;
        else
        {
            bool left=isCBT(root->left,2*index+1,cnt);
            bool right=isCBT(root->right,2*index+2,cnt);
        
            return (left && right);
        }
    }
    
    bool isMaxOrder(Node* root)
    {
        if(root->left==NULL && root->right==NULL)
        return true;
        
        if(root->right==NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            
            return (left && right && 
            (root->data > root->left->data && root->data > root->right->data ));
        }
    }
    bool isHeap(struct Node* tree) {
        
        int index=0;
        int totalCount=countNodes(tree);
        
        if( isCBT(tree,index,totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        cout<<"Enter the values: ";
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}