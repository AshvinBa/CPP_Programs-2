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

    ~node()
    {
        int val;
        val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"The deleted element is: "<<val<<endl;
    }
};

void insertNode(node* &tail,int ele,int d)
{
    node* newnode=new node(d);
    if(tail==NULL)
    {
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        node* curr=tail;

        while(curr->data!=ele)
        {
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
}

void print(node* &tail)
{
    node* temp=tail;

    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}

void deleteNode(node* tail,int val)
{
    if(tail==NULL)
    {
        cout<<"The list is under flow.";
        return;
    }
    else
    {
        node* prev=tail;
        node* curr=prev->next;

        while(curr->data!=val)
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
    node* tail=NULL;
    insertNode(tail,1,1);
    insertNode(tail,1,2);
    insertNode(tail,2,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    print(tail);    

    deleteNode(tail,3);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
return 0;
}









