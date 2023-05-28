/*
Nth node from end of linked list

Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.  
Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of n the return -1.

*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);
class Solution{
public:

    int getNthFromLast(Node *head, int n)
    {
        Node* first=head;
        Node* second=head;
        int cnt=0;
        
        for(int i=1;i<n;i++)
        {
            second=second->next;
            if(second==NULL)return -1;
            
        }
        while(second->next)
        {
            first=first->next;
            second=second->next;
        }
        return first->data;
    }
};

int main()
{
  int T,i,n,l,k;
    struct Node *head = NULL,  *tail = NULL;
    cout<<"Enter the Limit of Linked List: ";
    cin>>n;
    cout<<"Enter the value of Node: ";
    cin>>k;
    cout<<"Enter the values: ";
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<"Answer: "<<obj.getNthFromLast(head, k)<<endl;
    return 0;
}