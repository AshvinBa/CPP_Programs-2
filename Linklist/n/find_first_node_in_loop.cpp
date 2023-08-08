/*
Find the first node of loop in linked list

Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. If a loop is present return the node data of the first node of the loop else return -1.

Example 1:
Input:
Output: 3
Explanation:
We can see that there exists a loop 
in the given linked list and the first
node of the loop is 3.
 
Example 2:
Input:
Output: -1
Explanation: No loop exists in the above
linked list.So the output is -1.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        if(head==NULL)
        return -1;
        
        map<Node*,bool>visit;
        
        Node* temp=head;
        Node* ret=head;
        while(temp!=NULL)
        {
            if(visit[temp]==true)
            {
                int n=temp->data;
                return n;
            }
            visit[temp]=true;
            temp=temp->next;
        }
        return -1;
    }
};

int main()
{
    int t;
    cout<<"Enter the values of t: ";
    cin>>t;
    while(t--)
    {
        int n, num;
        cout<<"Enter the limit: ";
        cin>>n;
        cout<<"Enter the values: ";
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cout<<"Enter the position of loop: ";
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<"\nAnswer: ";
        cout<<ans<<"\n";
    }
	return 0;
}