/*
Insert in Sorted way in a Sorted DLL
EasyAccuracy: 28.25%Submissions: 26K+Points: 2
LAST DAY To Avail 35% Discount on GfG Courses!

banner
Given a sorted doubly linked list and an element X, your need to insert the element X into correct position in the sorted DLL.

Example: 1
Input:
LinkedList: 3<->5<->8<->10<->12. 
X = 9
Output:
3<->5<->8<->9<->10<->12.

Your Task:
You only need to complete the function sortedInsert() that takes head reference and x as arguments and returns the head of the modified list. The printing and checking tasks are done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 103
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* prev, *next;
};

struct Node* getNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}
void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
bool isChecked(Node *head)
{
    int lengthF=0;
    int lengthB=0;
    Node *temp=head;
    while(temp->next)
    {
        temp=temp->next;
        lengthF++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        lengthB++;
    }
    
    return lengthF==lengthB;
}

Node* sortedInsert(Node * head, int x);

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
	    struct Node* new_node = NULL;
	    int n, tmp, x;
        cout<<"Enter the limit of the DLL: ";
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        cout<<"Enter the values of the DLL: ";
	    cin>>x;
	    head = getNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=getNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
        cout<<"Enter the inserting Values: ";
	    cin>>x;
	    head=sortedInsert(head, x);
	    
	    if(isChecked(head))
	    printList(head);
	    else
	    cout<<"The node has not been inserted correctly. Please fix the prev and next pointers";
	    cout<<endl;
    }
	return 0;
}

Node* sortedInsert(Node * head, int x)
{
    if(!head)
    {
        return head;
    }
    Node* node=getNode(x);
    
    if(head->data >= node->data)
    {
        head->prev=node;
        node->next=head;
        return node;
    }
    
    Node* temp=head;
    
    while(temp!=NULL)
    {
        if(temp->data >= node->data)
        {
            temp->prev->next=node;
            node->prev=temp->prev;
            node->next=temp;
            temp->prev=node;
            break;
        }
        else if(temp->next == NULL)
        {
            temp->next=node;
            node->prev=temp;
            break;
        }
        else 
        {
            temp=temp->next;
        }
    }
    return head;   
};