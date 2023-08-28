#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
    cout<<"Answer: "<<endl;
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node* removeDuplicates(Node *root);
int main() {
		int K;
        cout<<"Enter the size of Key: ";
		cin>>K;
		Node *head = NULL;
        Node *temp = head;
        
        cout<<"Enter the data: ";
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	return 0;
}


Node *removeDuplicates(Node *head)
{
    if(head==NULL)
    return NULL;

    Node* curr=head;
    
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            Node* next_next=curr->next->next;
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}
