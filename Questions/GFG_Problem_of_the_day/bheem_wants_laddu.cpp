/*
Bheem Wants Ladoos

Chhota Bheem wants to eat the maximum number of ladoos in Dholakpur on Independence Day. The houses in Dholakpur are arranged in the form of a binary tree and have ladoos the same as their house number. Chhota Bheem is standing at his home initially. 
Find the maximum ladoos he can eat if he can go to houses within a maximum distance k from his house. The number of ladoos at his home should also be included in the sum.

Note: Every house has distinct ladoos in it. 
Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
home = 9, K = 1
Output:
22
Explanation:
Initially Bheem at 9, so sum = 9
In 2nd move he went to 5, sum=9+5=14
In 3rd move he went to 7, sum=14+7=21
In 4th move he went to 1, sum=21+1=22
So within K distance bheem can get 22 ladoos. 

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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


class Solution{

    public:
    Node* king;
    unordered_map<Node*,Node*> parent;
    
    int levelOrder(int k)
    {
        int sum=0;
        queue<Node*>q;
        q.push(king);
        unordered_map<Node*,bool> vis;
        vis[king]=true;
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto curr=q.front();
                q.pop();
                sum+=curr->data;
                if(curr->left && !vis[curr->left])
                {
                    vis[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right])
                {
                    vis[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]])
                {
                    vis[parent[curr]]=true;
                    q.push(parent[curr]);
                }
            }
            if(steps==k) break;
            steps++;
        }
        return sum;
    }
    
    void MakeParent(Node* root,int home)
    {
        queue<Node*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            
            if(curr->data==home)
            {
                king=curr;
            }
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    
    
    int ladoos(Node* root, int home, int k)
    {
        MakeParent(root,home);
        return levelOrder(k);
    }
};


// Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}