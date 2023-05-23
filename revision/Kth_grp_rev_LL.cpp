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

node* kreverse(node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    node* next=NULL;
    node* prev=NULL;
    node* curr=head;
    int cnt=0;

    while(curr!=NULL && cnt<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }

    if(head!=NULL)
    {
        head->next=kreverse(head,k);
    }
    return prev;
}

void print(node* head)
{
    node* temp=head;
    cout<<"Print: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;

    node* head=NULL;
    node* tail=NULL;
    int val;
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
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
    int k;
    cout<<"Enter the value of K: ";
    cin>>k;
    head = kreverse(head,k);

    print(head);
return 0;
}