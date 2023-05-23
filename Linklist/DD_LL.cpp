#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }

    ~node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"The deleleted element is: "<<val<<endl;
    }
};

void insertAtHead(node* &head,node* &tail,int d)
{
    node* newnode=new node(d);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertAtTail(node* &head,node* &tail,int d)
{
    node* newnode=new node(d);
    if(tail==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertAtPosition(node* &head,node* &tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,tail,d);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<position)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp==NULL)
    {
        insertAtTail(head,tail,d);
        return;        
    }

    node* newnode=new node(d);

    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

void display(node* head,node* tail)
{
    node* temp=head;
    cout<<"The List is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int delfromFirst(node* &head,node* &tail)
{
    if(head==NULL)
    {
        cout<<"Underflow. ";
    }
    else
    {
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
}

int delfromLast(node* &head,node* &tail)
{
    if(tail==NULL)
    {
        cout<<"Underflow. ";
    }
    else
    {
        node* temp=tail;
        temp->prev->next=NULL;
        tail=temp->prev;
        temp->prev=NULL;
        delete temp;
    }
}

void deleteFromPosition(node* &head,node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"Underflow.";
    }

    if(position==1)
    {
        delfromFirst(head,tail);
        return;
    }
    int cnt=1;
    node* temp=head;
    node* prev1=NULL;

    while(cnt<position)
    {
        prev1=temp;
        temp=temp->next;
        cnt++;
    }

    if(temp==NULL)
    {
        delfromLast(head,tail);
        return;
    }

    prev1->next=temp->next;
    // temp->next->prev=prev1;
    temp->next=NULL;
    delete temp;
}

int main(){

    node* head=NULL;
    node* tail=NULL;
    
    int d;
    do{
    cout<<"\n\n\t***OPERATIONS***"<<endl;
    cout<<"\t1) Enter at first."<<endl;
    cout<<"\t2) Enter at last."<<endl;
    cout<<"\t3) Enter at specific position."<<endl;
    cout<<"\t4) Delete from first."<<endl;
    cout<<"\t5) Delete from last."<<endl;
    cout<<"\t6) Delete from Specific Position."<<endl;
    cout<<"\t7) Display."<<endl;
    cout<<"\t8) Exit."<<endl;
    cout<<"\n\tEnter the choice: ";
    cin>>d;

    switch(d)
    {
        case 1:
        {
            int n;
            cout<<"\tEnter the digit: ";
            cin>>n;
            insertAtHead(head,tail,n);
        }
        break;
        
        case 2:
        {
            int n;
            cout<<"\tEnter the digit: ";
            cin>>n;
            insertAtTail(head,tail,n);
        }
        break;

        case 3:
        {
            int n,po;
            cout<<"\tEnter the position: ";
            cin>>n;
            cout<<"Enter the digit: ";
            cin>>po;
            insertAtPosition(head,tail,po,n);
        }
        break;

        case 4:
        {
            delfromFirst(head,tail);
        }
        break;

        case 5:
        {
            delfromLast(head,tail);
        }
        break;

        case 6:
        {
            int po;
            cout<<"\tEnter the position for delete: ";
            cin>>po;
            deleteFromPosition(head,tail,po);
        }
        break;

        case 7:
        {
            display(head,tail);
        }
        break;

        case 8:
        {
            cout<<"Exit.";
        }
        break;
    }
    }

    while(d!=8);
return 0;
}

/*

        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 1
        Enter the digit: 1


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 2


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 3


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 4


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 5


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 6


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 7


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 8


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 9


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 2
        Enter the digit: 10


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 7
The List is: 1 2 3 4 5 6 7 8 9 10 


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 4
The deleleted element is: 1


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 4
The deleleted element is: 2


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 7
The List is: 3 4 5 6 7 8 9 10 


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 5
The deleleted element is: 10


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 5
The deleleted element is: 9


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 6
        Enter the position for delete: 5
The deleleted element is: 7


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 7
The List is: 3 4 5 6 8 


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 6
        Enter the position for delete: 1
The deleleted element is: 3


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 6
        Enter the position for delete: 4
The deleleted element is: 8


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 6
        Enter the position for delete: 3
The deleleted element is: 6


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 7
The List is: 4 5 


        ***OPERATIONS***
        1) Enter at first.
        2) Enter at last.
        3) Enter at specific position.
        4) Delete from first.
        5) Delete from last.
        6) Delete from Specific Position.
        7) Display.
        8) Exit.

        Enter the choice: 8
Exit.

*/
