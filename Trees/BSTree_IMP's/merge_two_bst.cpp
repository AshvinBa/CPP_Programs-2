/*
Merge two BST 's
Given two BSTs, return elements of both BSTs in sorted form.

TC=O(n+m);


Example 1:
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
Example 2:

Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.

Expected Time Complexity: O(M+N) where M and N are the sizes of the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + M + N(for storing the answer)).

Constraints:
1 ≤ Number of Nodes ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

class Solution
{
    public:
    void inorder(Node *root,vector<int>&mp)
    {
        if(root==NULL)
        return;
        
        inorder(root->left,mp);
        mp.push_back(root->data);
        inorder(root->right,mp);
    }
    
    vector<int> mergeArr(vector<int>a1,vector<int>a2)
    {
        int i=0,j=0;
        int n=a1.size(),m=a2.size();
        vector<int>ans;
        
        while(i<n and j<m)
        {
            if(a1[i] < a2[j])
            {
                ans.push_back(a1[i]);
                i++;
            }
            else
            {
                ans.push_back(a2[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            ans.push_back(a1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(a2[j]);
            j++;
        }
        
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        
        vector<int>arr1,arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);
        
        vector<int>ans=mergeArr(arr1,arr2);
        return ans;
    }
};

int main() {

   int t;
   string tc;
   cout<<"Enter the test case values: ";
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
       string s; 
       cout<<"Enter the values for 1st BST: ";
       getline(cin, s);
       Node* root1 = buildTree(s);

       cout<<"Enter the values for 2nd BST: ";
       getline(cin, s);
       Node* root2 = buildTree(s);
    
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       cout<<"Answer: "<<endl;
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
   }
   return 0;
}



// Approach - 2
/*

//It is optimise solution .
which has TC=O(h1+h2).

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    int countNodes(Node* &head)
    {
        int cnt=0;
        Node* temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->right;
        }
        return cnt;
    }
    
    void convertIntoSortedDLL(Node *root,Node* &head)
    {
        if(root==NULL)
        return;
        
        convertIntoSortedDLL(root->right,head);
        
        root->right=head;
        
        if(head!=NULL)
        head->left=root;
        
        head=root;
        
        convertIntoSortedDLL(root->left,head);
    }
    
    Node* mergeLinkedLidt(Node* head1,Node* head2)
    {
        Node* head=NULL;
        Node* tail=NULL;
        
        while(head1 !=NULL && head2 !=NULL)
        {
            if(head1->data < head2->data)
            {
                if(head==NULL)
                {
                    head=head1;
                    tail=head1;
                    head1=head1->right;
                }
                else
                {
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
                }
            }
            else
            {
                if(head==NULL)
                {
                    head=head2;
                    tail=head2;
                    head2=head2->right;
                }
                else
                {
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
                }
            }
        }
        
        while(head1!=NULL)
        {
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
        
        while(head2=NULL)
        {
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
        }
        return head;
    }
    
    Node* sortedLLToBST(Node* &head,int n)
    {
        if(n<=0 || head==NULL)
        {
            return NULL;
        }
        
        Node* left=sortedLLToBST(head,n/2);
        
        Node* root=head;
        root->left=left;
        
        head=head->right;
        
        root->right=sortedLLToBST(head,((n-n)/(2-1)));
        
        return root;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        Node* head1=NULL;
        convertIntoSortedDLL(root1,head1);
        head1->left=NULL;
        
        Node* head2=NULL;
        convertIntoSortedDLL(root2,head2);
        head2->left=NULL;
        
        Node* head=mergeLinkedLidt(head1,head2);
        
        return sortedLLToBST(head,countNodes(head));
    }
    */