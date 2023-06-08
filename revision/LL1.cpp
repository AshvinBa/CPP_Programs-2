#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is Free for node with data: "<<val<<endl;
    }
};

void insertAtHead(int d,Node* &head,Node* &tail)
{
    Node* newNod=new Node(d);
    if(head==NULL)
    {
        head=newNod;
        tail=newNod;
    }
    else
    {
    newNod->next=head;
    head=newNod;
    }
}

void insertAtTail(int d,Node* &head,Node* &tail)
{
    Node* temp=new Node(d);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void insertAtPosition(int d,int position,Node* &head,Node* &tail)
{
    if(position==1)
    {
        insertAtHead(d,head,tail);
        return;
    }

    Node* temp=head;
    int cnt=1;

    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    Node* newNode=new Node(d);

    if(temp->next==NULL)
    {
        insertAtTail(d,head,tail);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteAthead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"No Element in Linked List."<<endl;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

void deleteAtTail(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"No Element in Linked List."<<endl;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;                                                        
        temp=temp->next;
    }
    prev->next=temp->next;
    prev->next=NULL;
    delete temp;    
}

void deleatAtPosition(int position,Node* &head,Node* &tail)
{
    if(position==1)
    {
        deleteAthead(head,tail);
        return;
    }
    Node* temp=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<position)
    {
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        deleteAtTail(head,tail);
        return;
    }
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
}

void print(Node* &head)
{

    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(5,head,tail);    
    insertAtHead(15,head,tail);
    print(head);
    insertAtTail(20,head,tail);
    insertAtTail(25,head,tail);
    print(head);
    insertAtPosition(22,3,head,tail);
    insertAtPosition(22,6,head,tail);
    print(head);
    deleteAthead(head,tail);
    print(head);
    deleteAtTail(head,tail);
    print(head);
    deleteAtTail(head,tail);
    print(head);
    deleatAtPosition(2,head,tail);
    print(head);
    deleatAtPosition(1,head,tail);
    print(head);
return 0;
}