/*
Rotate a Linked List
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:
Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Example 2:
Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
    public:
    //code to Rotate the values.    
    Node* rotate(Node* head, int k)
    {
        if(k==0)
        return head;
        
        Node* temp=head;
        int cnt=1;
        while(cnt<k && temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        
        Node* curr=temp;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=head;
        head->prev=temp;
        head=curr->next;
        head->prev=NULL;
        curr->next=NULL;
        return head;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
        int n, val, k;
        cout<<"Enter the limit of the Linked List: ";
        cin>>n;
        cout<<"Enter the values: ";
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        cout<<"Enter the Rotate Values: ";
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    
    return 0;
}