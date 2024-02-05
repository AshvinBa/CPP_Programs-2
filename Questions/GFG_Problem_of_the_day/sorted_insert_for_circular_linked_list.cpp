/*
Sorted insert for circular linked list
Given a sorted circular linked list of length n, the task is to insert a new node
in this circular list so that it remains a sorted circular linked list.

Example 1:
Input:
n = 3
LinkedList = 1->2->4
(the first and last node is connected, i.e. 4 --> 1)
data = 2
Output: 
1 2 2 4
Explanation:
We can add 2 after the second node.

Example 2:
Input:
n = 4
LinkedList = 1->4->7->9
(the first and last node is connected, i.e. 9 --> 1)
data = 5
Output: 
1 4 5 7 9
Explanation:
We can add 5 after the second node.
Your Task:
The task is to complete the function sortedInsert() which should insert the new node
into the given circular linked list and return the head of the linked list.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 105

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node* temp=head;
        Node* curr=NULL;
        Node* newNode=new Node(data);
        
        if(!head)
        {
            newNode->next=newNode;
            return newNode;
        }
        
        do
        {
            curr=temp;
            temp=temp->next;
            if(curr->data <= data && temp->data >= data)
            {
                break;
            }
        }
        while(temp!=head);
        
        curr->next=newNode;
        newNode->next=temp;
        
        if(data<head->data)
        return newNode;
        
        return head;
    }
};


/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}


int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
    }
  return 0;
}
