/*
Normal BST to Balanced BST

Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

Example1:
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Example2:
Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ 
     2        1                    4

Your Task:
The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Here N denotes total number of nodes in given BST.

Constraints:
1 <= N <= 105
1 <= Node data <= 109

*/

//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void inorder(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    Node* inorderToBST(int s,int e,vector<int>&ans)
    {
        if(s>e)
        return NULL;
        
        int mid=(s+e)/2;
        Node* root=new Node(ans[mid]);
        root->left= inorderToBST(s,mid-1,ans);
        root->right= inorderToBST(mid+1,e,ans);
    
    
        return root;
    }
    
    Node* buildBalancedTree(Node* root)
    {
        vector<int>ans;
        inorder(root,ans);
        return inorderToBST(0,ans.size()-1,ans);
    }
};

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) 
    return 0;
  int lDepth = height(node->left);
  int rDepth = height(node->right);
  if (lDepth > rDepth) 
    return(lDepth+1);
  else 
    return(rDepth+1);
} 
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cout<<"ENter the number of test cases: ";
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        cout<<"Enter the values: ";
        getline(cin,tree);
        root = buildTree(tree);
        Solution obj;
        root = obj.buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}