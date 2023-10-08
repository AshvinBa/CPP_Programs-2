/*
Move all zeros to the front of the linked list

Given a linked list, the task is to move all 0s to the front of the linked list. The order of all another element except 0 should be same after rearrangement.

Example 1:
Input:  0 -> 4 -> 0 -> 5 -> 0
Output: 0 -> 0 -> 0 -> 4 -> 5
Explanation: After moving all 0s of the given
list to the front, the list is:
0 -> 0 -> 0 -> 4 -> 5

Example 2:
Input: 0 -> 1 -> 0 -> 1 -> 2
Output: 0 -> 0 -> 1 -> 1 -> 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function moveZeroes() which takes head node of the linked list as input parameter.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 50
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

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cout<<"Enter the Number of test cases: ";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter the Limit: ";
        cin>>n;
        int q;
        vector<int> v;
        struct Node *Head=NULL;
        cout<<"Enter the values: ";
        for(int i=0;i<n;i++)
        {
            cin>>q;
            v.push_back(q);
        }
        reverse(v.begin(),v.end());
        for(auto q:v)
            push(&Head,q);
        moveZeroes(&Head);
        display(Head);

    }
}

void moveZeroes(struct Node **head)
{
    if(*head == NULL)
    return;
    
    Node *temp=(*head)->next,*prev=*head;
    
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            Node *curr=temp;
            temp=temp->next;
            prev->next=temp;
            curr->next=*head;
            *head=curr;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }    
}
