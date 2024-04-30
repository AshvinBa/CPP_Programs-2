/*
Delete Middle of Linked List

Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list has single node, then it should return NULL.

Example 1:
Input:
LinkedList: 1->2->3->4->5
Output: 
1 2 4 5

Example 2:
Input:
LinkedList: 2->4->6->7->5->1
Output: 
2 4 6 5 1
Your Task:
The task is to complete the function deleteMid() which takes head of the linkedlist  and return head of the linkedlist with middle element deleted from the linked list. If the linked list is empty or contains single element then it should return NULL.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 105
1 <= value[i] <= 109

*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if(head->next==NULL)
        return NULL;
        
        Node *slow=head, *fast=head, *temp=NULL;
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=slow->next;
        return head;
    }
};
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
    cout<<"Number of test cases: ";
	cin>>t;
	while(t--)
	{
		int n;
        cout<<"Size of LL: ";
		cin>>n;

		int data;
        cout<<"Enter the data :";
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
        cout<<"The updated Linked List is: ";
		printList(head); 
	}
	return 0; 
} 
