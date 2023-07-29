#include<iostream>
using namespace std;

class Node
{
    public: 

    int data;
    Node* prev;
    Node* next;
 
    //constructor
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }

    // Destructor
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"The Deleted Node is: "<<val;
    }
};

int getlen(Node* head)
{
    int cnt=1;
    Node* temp=head;
    if(head==NULL)
    {
        cout<<"\nNo Any Node Present in list.";
    }
    else
    {
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
}

void print(Node* head)
{
    Node* temp=head;
    if(head==NULL)
    {
        cout<<"The Element is Not present in List.";
    }
    else
    {
        cout<<"\nThe Elements are: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;        
        }
    }
    cout<<endl;
}

bool search(Node* head,int key)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void insertAtHead(Node* &head,Node* &tail,int val)
{
    Node* temp=new Node(val);
    if(head==NULL && tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int val)
{
    Node* temp=new Node(val);
    if(head==NULL && tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int val)
{
    if(position==1)
    {
        insertAtHead(head,tail,val);
        return;
    }
    Node* temp=head;
    int cnt=1;
    
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(head,tail,val);
        return;
    }
    Node* newnode=new Node(val);

    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

void deleteHead(Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"No Element in Linked List.";
        return;
    }
    Node* temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp; 
}

void deleteTail(Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        cout<<"No Element in Liked List.";
        return;
    }
    Node* temp=tail;
    tail=temp->prev;
    temp->prev->next=NULL;
    delete temp;
}

void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    if(position==1)
    {
        deleteHead(head,tail);
        return;
    }
    Node* temp=head;

    if(temp->next==NULL)
    {
        deleteTail(head,tail);
        return;
    }
    int cnt=1;
    Node* curr=head;
    Node* prev=NULL;
    while(cnt<position)
    {
        cnt++;
        prev=curr;
        curr=curr->next;
    }

    prev->next=curr->next;
    curr->next->prev=prev;
    curr->next=NULL;
    delete curr;   
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;

    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,1);
    print(head);


return 0;
}