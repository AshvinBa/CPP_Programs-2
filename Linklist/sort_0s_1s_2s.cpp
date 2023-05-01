// Algorith to sort 0s,1s,2s in Linked List.

#include<iostream>
using namespace std;

// Approach-1
/*

Node* sortList(Node *head)
{
    int zeroCount=0;
    int onesCount=0;
    int twosCount=0;

    Node* temp=head;

    while(temp!=NULL)
    {
        if(temp->data==0)
        zeroCount++;
        
        if(temp->data==1)
        onesCount++;
        
        if(temp->data==2)
        twosCount++;

        temp=temp->next;
    }

    temp=head;

    while(temp!=NULL)
    {
        if(zeroCount!=0)
        {
            temp->data=0;
            zeroCount--;
        }
        else if(onesCount!=0)
        {
            temp->data=1;
            onesCount--;
        }
        else if(twosCount!=0)
        {
            temp->data=2;
            twosCount--;
        }
        temp=temp->next;
    }
    return head;
}


*/


// Approach-2
/*
    void insertAtTail(Node* &tail,Node* curr)
    {
        tail->next=curr;
        tail=curr;
    }
    
    Node* segregate(Node *head) {
        
        Node* zeroHead=new Node(-1);
        Node* zerotail=zeroHead;
        Node* oneHead=new Node(-1);
        Node* onetail=oneHead;
        Node* twoHead=new Node(-1);
        Node* twotail=twoHead;
        
        Node* curr=head;
        
        while(curr!=NULL)
        {
            int value=curr->data;
            
            if(value==0)
            {
                insertAtTail(zerotail,curr);
            }
            else if(value==1)
            {
                insertAtTail(onetail,curr);
            }
            else if(value==2)
            {
                insertAtTail(twotail,curr);
            }
            curr=curr->next;
        }
        
        if(oneHead->next!=NULL)
        {
            zerotail->next=oneHead->next;
        }
        else
        {
            zerotail->next=twoHead->next;
        }
        
        onetail->next=twoHead->next;
        twotail->next=NULL;
        
        head=zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        
        return head;
    }
*/