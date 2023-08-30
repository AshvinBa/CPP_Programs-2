/*
Delete a Node in Single Linked List
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:
Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. 

Example 2:
Input: 1 -> 5 -> 2 -> 9 
x = 2
Output: 1 -> 2 -> 9
Explanation: 
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.
*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

int main()
{
  int i, n, l;
    struct Node *head = NULL,  *tail = NULL;
        cout<<"Enter the Limit: ";
        cin>>n;
        cout<<"Enter the value: ";
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
    cout<<"Enter the position: ";
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    return 0;
}

Node* deleteNode(Node *head,int x)
{
    if(head==NULL && head->next==NULL)
    return NULL;
    
    Node* temp=head;
    
    if(x==1)
    {
        head=head->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
    Node* prev=NULL;
    int cnt=1;
    
    while(cnt<x)
    {
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
    return head;
}
