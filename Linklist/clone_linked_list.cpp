/*
#include<bits/stdc++.h>
using namespace std;


// algorithm-1

class Solution
{
    private:
    
    void insertAtTail(Node* &head,Node* &tail,int d)
    {
        Node* temp=new Node(d);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return ;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
         Node* cloneHead=NULL;
         Node* cloneTail=NULL;
         
         Node* temp=head;
         
         while(temp!=NULL)
         {
             insertAtTail(cloneHead,cloneTail,temp->data);
             temp=temp->next;
         }
         
         unordered_map<Node*,Node*>oldToNew;
         
         Node* original=head;
         Node* clone=cloneHead;
         
         while(original!=NULL && clone!=NULL)
         {
             oldToNew[original]=clone;
             original=original->next;
             clone=clone->next;
         }
         
         original=head;
         clone=cloneHead;
         
         while(original!=NULL)
         {
             clone->arb=oldToNew[original->arb];
             original=original->next;
             clone=clone->next;
         }
         return cloneHead;
         
    }

};
*/