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
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Approach 1
    int size(Node* head)
    {
        Node* temp=head;
        int cnt=1;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    
    Node* rotate(Node* head, int k)
    {
        if(head== NULL)
        return head;
        
        int n=size(head);
        int loop=k%n;
        loop=n-loop;
        
        if(n==1 || loop==n)
        return head;
        
        int j=1;
        Node* temp=head;
        Node* firstNode=head;
        
        while(temp!=NULL)
        {
            j++;
            if(j==loop)
            {
                firstNode=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        temp=firstNode;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return firstNode;
    }
  
};

  //Function to rotate a linked list.
    
    //Approach 2  --> wrong sol
    

    // Node* rotate(Node* head, int k)
    // {
    //     if(!head || !head->next || k==0)return head;
        
    //     Node* curr=head;
    //     int len=1;
        
    //     while(curr->next && ++len)
    //         curr=curr->next;
        
    //     curr->next=head;
    //     k=k%len;
    //     k=len-k;
        
    //     while(k--)curr=curr->next;
        
        
    //     head=curr->next;
    //     curr->next=NULL;
        
    //     return head;
    // }
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
    int t;
    cout<<"Enter the value of t: ";
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cout<<"Enter the size: ";
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
        cout<<"Enter the values to ratate: ";
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

