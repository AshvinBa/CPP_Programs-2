/*
Union of Two Linked Lists
Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 

Example 2:
Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output
*/

#include<bits/stdc++.h>
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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int >ele;
        while(head1!=NULL)
        {
            ele.insert(head1->data);
            head1=head1->next;
        }
        
        while(head2!=NULL)
        {
            ele.insert(head2->data);
            head2=head2->next;
        }
        
        Node* curr=NULL;
        Node* head;
        
        for(auto i:ele)
        {
            Node* newNode=new Node(i);
            if(curr==NULL)
            {
                head=newNode;
                curr=head;
                
            }
            else
            {
                curr->next=newNode;
                curr=newNode;
            }
        }
        return head;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
        int n, m;
        cout<<"Enter the limit of first Linked List: ";
        cin>>n;
        Node* first = buildList(n);
        
        cout<<"Enter the limit of second Linked List: ";
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    return 0;
}
