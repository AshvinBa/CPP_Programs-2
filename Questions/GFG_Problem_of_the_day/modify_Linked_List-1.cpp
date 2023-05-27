/*
Modify Linked List-1

Given a singly linked list containing N nodes. Modify the Linked list as follows:

1. Modify the value of the first half nodes such that 1st node's new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes.
2. Replace the second half of nodes with the initial values of the first half nodes(values before modifying the nodes).
3. If N is odd then the value of the middle node remains unchanged.

Example 1:

Input:
N = 5
linked list = 10 -> 4 -> 5 -> 3 -> 6
Output:
-4 -1 5 4 10
Explanation:
For first half nodes modified list will be:
-4 -> -1 -> 5 -> 3 -> 6
For second half nodes modified list will be:
-4 -> -1 -> 5 -> 4 -> 10

*/
#include <bits/stdc++.h>
using namespace std;


struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        Node *slow=head;
        Node *fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast!=NULL)
        {
            slow=slow->next;  //for odd number of array size.
        }
        
        if(slow==NULL)
        {
            return head;
        }
        
        Node* last=slow;
        
        auto reverse=[&last](Node* curr,Node* prev)
        {
            while(curr!=NULL)
            {
                last=curr;
                Node* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
        };
        
        reverse(slow,NULL);
        Node* front=head;
        Node* back=last;
        
        while(back!=NULL)
        {
            int temp=front->data;
            
            front->data = back->data - front->data;
            back->data=temp;
            
            front=front->next;
            back=back->next;
        }
        reverse(last,NULL);
        return head;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}