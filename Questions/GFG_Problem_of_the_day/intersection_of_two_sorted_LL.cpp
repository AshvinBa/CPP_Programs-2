/*
Intersection of two sorted Linked lists

Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.
Note: The elements of the linked list are not necessarily distinct.

Example 1:
Input:
LinkedList1 = 1->2->3->4->6
LinkedList2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two
linked list, 2, 4 and 6 are the elements
in the intersection.

Example 2:
Input:
LinkedList1 = 10->20->40->50
LinkedList2 = 15->40
Output: 40
Your Task:
You don't have to take any input of print anything. Your task is to complete the function findIntersection(), which will take head of both of the linked lists as input and should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n, m are the size of the respective linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 104

*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}

class Solution
{
    public:
    
    void insertAtTail(Node* &head,Node* &tail,int data)
    {
        Node* temp=new Node(data);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    Node* findIntersection(Node* head1, Node* head2)
    {
        Node *newhead=NULL , *newtail=NULL;
        Node *curr1=head1,*curr2=head2;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->data == curr2->data)
            {
                insertAtTail(newhead,newtail,curr1->data);
                curr1=curr1->next;
                curr2=curr2->next;
            }
            else if(curr1->data < curr2->data)
            {
                curr1=curr1->next;
            }
            else if(curr1->data > curr2->data)
            {
                curr2=curr2->next;
            }
        }
        return newhead;
    }
};

int main()
{
	int t;
    cout<<"Enter the number Limit: ";
	cin>>t;
	while(t--)
	{
	    int n,m;
        cout<<"Insert values for LL1: ";
	    cin>> n ;

	    cout<<"Insert values for LL2: ";
	    cin>> m ;
        
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
