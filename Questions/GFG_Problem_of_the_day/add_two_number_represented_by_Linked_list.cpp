/*
Add two numbers represented by linked lists

Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:
Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Example 2:
Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
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


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        if(head==NULL)
        return NULL;
        
        Node* next=NULL;
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node* temp=NULL;
        while(num1 and num1->data==0)
        {
            temp=num1;
            num1=num1->next;
        }
        if(temp)
        temp->next=NULL;
        temp=NULL;
        
        while(num2 and num2->data==0)
        {
            temp=num2;
            num2=num2->next;
        }
        if(temp)
        temp->next=NULL;
        
        if(!num1 and !num2)
        return new Node(0);
        
        if(!num1)
        return num2;
        
        if(!num2)
        return num1;
        
        num1=reverse(num1);
        num2=reverse(num2);
        temp=new Node(1);
        
        Node *head1=num1 , *head2=num2,*ans=temp;
        int carry=0;
        
        while(head1 and head2)
        {
            int sum = head1->data + head2->data + carry;
            carry = sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1)
        {
            int sum=head1->data+carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head1=head1->next;
        }
        while(head2)
        {
            int sum=head2->data+carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head2=head2->next;
        }
        if(carry)
        temp->next = new Node(carry);
        return reverse(ans->next);
        
    }
    
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

