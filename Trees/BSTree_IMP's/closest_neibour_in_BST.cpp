/*
Closest Neighbour in BST
Given a binary search tree and a number N, find the greatest number in the binary search tree that is less than or equal to N. 

Example 1 :
Input : N = 24
Output : 21
Explanation : The greatest element in the tree which 
              is less than or equal to 24, is 21. 
              (Searching will be like 5->12->21)
 

Example 2 :
Input : N = 4
Output : 3
Explanation : The greatest element in the tree which 
              is less than or equal to 4, is 3. 
              (Searching will be like 5->2->3)

Your task :

You don't need to read input or print anything. Your task is to complete the function findMaxForN() which takes the root of the BST, and the integer N as input paramters and returns the greatest element less than or equal to N in the given BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1<=N<=103

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->key = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
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
	Node* root = newNode(stoi(ip[0]));

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

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

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
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

int findMaxForN(Node* root,int N);

int main()
{

	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int x;
		cin >> x;

		Node* root = buildTree(s);
		cout << findMaxForN(root, x) << endl;

	}
	return 1;
}

void solve(Node* root,int N,vector<int>&ans)
{
    if(root==NULL)
    return;
    
    solve(root->left,N,ans);
    ans.push_back(root->key);
    solve(root->right,N,ans);
}
  
int findMaxForN(Node* root, int N)
{
    vector<int>ans;
    solve(root,N,ans);
    int maxi=INT_MIN;
    
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]<=N)
        {
            maxi=max(ans[i],maxi);
        }
    }
    return maxi;
}