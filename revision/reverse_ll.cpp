#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};


void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* reverseList(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* forward=NULL;
    node* prev=head;
    node* curr=NULL;

    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}



int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        if(i==0)
        {
            head=new node(val);
            tail=head;
        }
        else
        {
            tail->next=new node(val);
            tail=tail->next;
        }
    }
    head=reverseList(head);
    print(head);    
return 0;
}















