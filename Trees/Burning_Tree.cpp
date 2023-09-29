/*
Burning Tree
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Example 1:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

Example 2:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 104
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
        if (i >= ip.size())
            break;
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
    Node* createParentMapping(Node* root,int target,map<Node*,Node*>&nodeToParent)
    {
      Node* res=NULL;
      
      queue<Node*>q;
      q.push(root);
      nodeToParent[root]=NULL;
      
      while(!q.empty())
      {
          Node* front=q.front();
          q.pop();
          
          if(front->data==target)
          {
              res=front;
          }
          
          if(front->left)
          {
              nodeToParent[front->left]=front;
              q.push(front->left);
          }
          
          if(front->right)
          {
              nodeToParent[front->right]=front;
              q.push(front->right);
          }
      }
      return res;
    }
    
    int burnTree(Node* root,map<Node*,Node*> &nodeToParent)
    {
        map<Node*,bool>visited;
        
        queue<Node*>q;
        
        q.push(root);
        visited[root]=true;
        
        int ans=0;
        
        while(!q.empty())
        {
            bool flag=0;
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left])
                {
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                
                if(front->right && !visited[front->right])
                {
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                }
            }
            if(flag==1)
            {
                ans++;
            }
        }
        return ans;
        }
  
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>nodeToParent;
        Node* targetNode=createParentMapping(root,target,nodeToParent);
        
        int ans=burnTree(targetNode,nodeToParent);
        return ans;
    }
};
int main() 
{
    string treeString;
        cout<<"Enter the numbers: ";
        getline(cin, treeString);

        int target;
        cout<<"Entre the target: ";
        cin>>target;
        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 
        cin.ignore();

    
    return 0;
}
