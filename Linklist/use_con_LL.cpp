#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free from node with data: " << value << endl;
    }
};

void InsertAtHead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAttail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* tail,Node* head,int position,int data)
{
    if(position==1)
    {
        InsertAtHead(head,data);
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
        InsertAttail(tail,data);
        return;
    }
    
    Node* nodeToinsert=new Node(data);
    
    nodeToinsert->next=temp->next;

    temp->next=nodeToinsert;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    Node* node1=new Node(10);

    Node* head=node1;
    Node* tail=node1;
    print(head);

    InsertAtHead(head,12);
    print(head);

    InsertAtHead(head,15);
    print(head);

    InsertAtHead(head,11);
    print(head);

    InsertAtHead(head,20);

    InsertAttail(tail,12);
    print(head);

    insertAtPosition(tail,head,3,44);

    InsertAttail(tail,15);
    print(head);

    deleteNode(1,head);
    print(head);

return 0;
}