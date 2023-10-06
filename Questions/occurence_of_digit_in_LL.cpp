/*
Occurence of an integer in a Linked List

Given a singly linked list and a key, count the number of occurrences of given key in the linked list.

Example 1:
Input:
N = 7
Link List = 1->2->1->2->1->3->1
search_for = 1
Output: 4
Explanation:1 appears 4 times.

Example 2:
Input:
N = 5
Link List = 1->2->1->2->1
search_for = 3
Output: 0
Explanation:3 appears 0 times.
Your Task:
You dont need to read input or print anything. Complete the function count() which takes the head of the link list and search_for i.e- the key as input parameters and returns the count of occurrences of the given key.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 ≤ N ≤ 10^4
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;

void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new node(value);
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= new node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    int count(struct node* head, int search_for)
    {
        int cnt=0;
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==search_for)
            {
                cnt++;
            }
            temp=temp->next;
        }
        return cnt;
    }
};
int main(void)
{
    int t,k,n,value;
    cout<<"Enter the number of test case: ";
     scanf("%d",&t);
     
     cout<<"Enter the number: ";
     while(t--)
     {
     insert();
     cout<<"Entre the number: ";
     scanf("%d",&k);

     Solution ob;
     value=ob.count(head, k);
     printf("%d\n",value);
     }
     return(0);
}
