/*
Print BST elements in given range

Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

Example 1:
Input:
       17
     /    \
    4     18
  /   \
 2     9
l = 4, h = 24
Output: 4 9 17 18

Example 2:
Input:
       16
     /    \
    7     20
  /   \
 1    10
l = 13, h = 23
Output: 16 20
Your Task:
You don't need to read input or print anything. Your task is to complete the function printNearNodes() which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in non-decreasing order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 104
1 ≤ l ≤ h ≤ 105


*/

#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    // Approach -1.

    /*
      void solve(Node* root,vector<int>&arr)
      {
          if(root==NULL)
          {
              return;
          }

          solve(root->left,arr);
          arr.push_back(root->data);
          solve(root->right,arr);
      }

      vector<int> printNearNodes(Node *root, int low, int high) {
          vector<int>arr;
          vector<int>ans;

          solve(root,arr);

          for(int i=0;i<arr.size();i++)
          {
              if(arr[i]>=low and arr[i]<=high)
              {
                  ans.push_back(arr[i]);
              }
          }
          return ans;
      }
      */

    // Approach - 2
    vector<int> solve(Node *root, int low, int high, int &i, vector<int> &ans)
    {

        if (root == NULL)
            return ans;

        vector<int> left = solve(root->left, low, high, i, ans);

        i++;

        if (root->data >= low and root->data <= high)
        {
            ans.push_back(root->data);
        }

        return solve(root->right, low, high, i, ans);
    }

    vector<int> printNearNodes(Node *root, int low, int high)
    {

        int i = 0;
        vector<int> ans;
        solve(root, low, high, i, ans);
        return ans;
    }
};

int main()
{

    int t;
    cout << "Enter the Number of test cases: ";
    scanf("%d ", &t);
    while (t--)
    {
        int k1, k2;
        string s;
        cout << "Enter the values: ";
        getline(cin, s);
        cout << "Enter the value of Low: ";
        scanf("%d ", &k1);
        cout << "Enter the values of high: ";
        scanf("%d ", &k2);
        Solution ob;
        Node *root = buildTree(s);
        vector<int> res = ob.printNearNodes(root, k1, k2);
        cout << "The following array between the given range: ";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 1;
}
