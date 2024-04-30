/*
Remove every kth node
Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

Example 1:
Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2
Output: 
1 -> 3 -> 5 -> 7
Explanation: 
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.

Example 2:
Input:
n = 10
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
k = 3
Output: 
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: 
After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
Your Task:
The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth node from the linked list and return its head.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 105
-109 <= elements of linked list <= 109
1 <= k <= n

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


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    
    *tail_ref = new_node;
}


class Solution {
    public:
    Node* deleteK(Node *head,int K){
        
        if(K==1)
        return NULL;
        Node *temp=head;
        Node *prev=NULL;
        int c=1;
        while(temp!=NULL)
        {
            if(c==K)
            {
                c=0;
                prev->next=temp->next;
            }
            else
            {
                prev=temp;
            }
            temp=temp->next;
            c++;
        }
        return head;
    }
};

int main()
{
    int T,i,n,l;
    cout<<"Enter the Number of testcases: ";
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
    cout<<"Enter the value of N: ";
        cin>>n;
        cout<<"Entre the values: ";
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cout<<"Enter the value of K: ";
        cin>>K;
        Solution obj;
        Node *res = obj.deleteK(head,K);
        Node *temp = res;
        cout<<"The list is Like: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
