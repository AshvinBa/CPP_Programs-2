/*

Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:
Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 
2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2
Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 
0
Explanation: K=9. The node that has
value nearest to K is 9. so the answer
is 0.

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void help(Node *root, int &ans, int K)
    {
        if (!root)
            return;
        ans = min(ans, abs(root->data - K));
        if (root->data > K)
        {
            help(root->left, ans, K);
        }
        else
        {
            help(root->right, ans, K);
        }
    }

    int minDiff(Node *root, int K)
    {
        int ans = INT_MAX;
        help(root, ans, K);
        return ans;
    }
};
// Function to Build Tree
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    cout << "Enter the limits: ";
    getline(cin, tc);
    t = stoi(tc);
    while(t--)
    {
        string s;
        cout << "Enter the values: ";
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        Solution ob;
        cout << ob.minDiff(root1, k);
        cout << endl;
    }
    return 0;
}
