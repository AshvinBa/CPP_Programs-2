/*
Brothers From Different Roots
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.


Example 1:
Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
 

Example 2:
Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes 2 BST's as parameter in form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
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

class Solution
{
public:

    int cnt=0;
    bool fetch(Node* root2,int k)
    {
        if(!root2)return false;
        if(k==root2->data)
        return true;
        bool x,y;
        x=false;
        y=false;
        
        if(k < root2->data)
        x=fetch(root2->left,k);
        else if(k > root2->data)
        y=fetch(root2->right,k);
        
        return x or y;
    }
    
    void solve(Node* root1,Node* root2,int x)
    {
        if(!root1)
        return;
        
        solve(root1->left,root2,x);
        if(fetch(root2,x-root1->data))
        cnt++;
        solve(root1->right,root2,x);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        cnt=0;
        solve(root1,root2,x);
        return cnt;
    }
};
int main()
{
    int t;
    cout<<"Entre the test cases: ";
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        cout<<"Enter the values for root1: ";
        getline(cin, tree1);
        cout<<"Enter the values for root2: ";
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cout<<"Enter the value for search: ";
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}
