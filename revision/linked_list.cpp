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
        cout<<"The Deleted element is: ";
        cout<<val<<endl;
    }

};

void insertAtHead(Node* &head,Node* &tail,int d)
{
    Node* temp=new Node(d);

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int d)
{
    Node* temp=new Node(d);

    if(tail==NULL)
    {
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,tail,d);
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
        insertAtTail(head,tail,d);
        return;
    }

    Node* newNode=new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}

int deletefromHead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"List is Underflow.";
    }
    else
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
}

int deletefromTail(Node* &head,Node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"List is Underflow.";
    }
    else
    {
        Node* prev=NULL;             
        Node* curr=head;

        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void display(Node* head)
{
    Node* temp=head;
    cout<<"The List is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
}

int main(){
    int s;
    cout<<"Enter the Number: ";
    cin>>s;
    Node* Node1=new Node(s);
    Node* head=Node1;
    Node* tail=Node1;

    int i;

    do{
    cout<<"\t***OPERATION***"<<endl;
    cout<<"\t1)insert at head."<<endl;
    cout<<"\t2)insert at tail."<<endl;
    cout<<"\t3)insert at spcific position."<<endl;
    cout<<"\t4)deleted from head."<<endl;
    cout<<"\t5)deleted from position. "<<endl;
    cout<<"\t6)Display Elements."<<endl;
    cout<<"\t7)Exit."<<endl;
    cout<<"\tEntre the choice: ";
    cin>>i;
    
    switch(i)
    {
        case 1:
        {
            int d;
            cout<<"Enter the digit for insert: ";
            cin>>d;
            insertAtHead(head,tail,d);
        }
        break;
        case 2:
        {
            int d;
            cout<<"Enter the digit for insert: ";
            cin>>d;
            insertAtTail(head,tail,d);
        }
        break;
        case 3:
        {
            int d;
            int index;
            cout<<"Enter the index to insert: ";
            cin>>index;
            cout<<"Enter the digit for insert: ";
            cin>>d;
            insertAtPosition(head,tail,index,d);
        }
        break;
        case 4:
        {
            deletefromHead(head,tail);
        }
        break;
        case 5:
        {
            int position;
            cout<<"Enter the position to delete: ";
            cin>>position;
            deletefromTail(head,tail,position);
        }
        break;
        case 6:
        {
            display(head);
        }
    }
    }
    while(i!=7);
return 0;
}