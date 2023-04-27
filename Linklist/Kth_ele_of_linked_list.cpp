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
*/

/*
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* first=head;
       Node* second=head;
       
       for(int i=1;i<n;i++)
       {
           second=second->next;
           if(second==NULL)
           return -1;
       }
       
       while(second->next!=NULL)
       {
           first=first->next;
           second=second->next;
       }
    return first->data;
}

*/