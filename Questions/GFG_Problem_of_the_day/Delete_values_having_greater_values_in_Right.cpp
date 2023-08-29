/*
Delete nodes having greater value on right

Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)

Example 1:
Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.

Example 2:
Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last
node has a greater value node on its right,
so all the nodes except the last node must
be removed.
*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
class Solution
{
    public:

    Node *compute(Node *head)
    {
        int MAX=-1e9;
        
        function<Node *(Node*)> traverse=[&](Node * curr)->Node*
        {
            if(curr==NULL)
            return NULL;
            
            Node* next=traverse(curr->next);//To Travarse at Forward
            
            if(next!=NULL)
            {
                Node* todelet=curr->next;
                curr->next=next;//To Travarse at Forward
                delete todelet;
            }
            
            MAX=max(MAX,curr->data);
             
            if(MAX>curr->data)
            {
                return curr->next;
            }
            else
            {
                return NULL;
            }
        };
        
        Node * first=traverse(head);
        if(first == NULL)
        return head;
        else
        return first;
    }
};

int main()
{
		int K;
        cout<<"Enter the size: ";
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
        cout<<"Enter the values: ";
		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        cout<<"The Answer is: ";
        print(result);
        cout<<endl;
 
}

// IP
/*12->15->10->11->5->6->2->3*/
// OP
// 15 11 6 3
