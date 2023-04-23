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
    }
};

void insertElement(Node* &tail,int num,int d)
{
    if(tail==NULL)
    {
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else
    {
        Node* curr=tail;

        while(curr->data != num)
        {
            curr=curr->next;
        }
        Node* newNode=new Node(d);
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void print(Node* tail)
{
    Node* temp=tail;

    if(tail==NULL)
    {
        cout<<"Its Empty.";
    }

    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}

void deleteElement(Node* &tail,int ele)
{
    if(tail==NULL)
    {
        cout<<"THE LINKED LINST IS EMPTY.";
        return;
    }
    else
    {
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=ele)
        {
            prev=curr;
            curr=curr->next;
        }    
        prev->next=curr->next;

        if(curr==prev)
        {
            tail=NULL;
        }
        else if(tail==curr)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}


int main(){
    Node* tail=NULL;
    insertElement(tail,5,0);
    print(tail);    
    insertElement(tail,0,1);
    insertElement(tail,1,2);
    insertElement(tail,2,3);
    insertElement(tail,3,4);
    insertElement(tail,4,5);
    insertElement(tail,5,6);
    insertElement(tail,6,7);
    insertElement(tail,7,8);
    print(tail);
    deleteElement(tail,5);
    deleteElement(tail,8);
    print(tail);
return 0;
}






