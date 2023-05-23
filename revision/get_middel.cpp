/*

#include<iostream>
using namespace std;

class node
{
    public: 
    int data;
    node* next;

    node(int d)
    {
        this->next=NULL;
        this->data=d;
    }
};

int getmiddle(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head->data;
    }

    if(head->next->next==NULL)
    {
        return head->next->data;
    }
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow->data;
}

int findMiddle(node* head)
{
    return getmiddle(head);
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
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
    
    cout<<"\nPrint The Linked List: ";
    print(head);
    cout<<"The Middle Element is: "<<findMiddle(head);
    return 0;
}

*/

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

int getLen(node* head)
{
    int cnt=0;
    node* temp=head;

    while(temp!=NULL)
    {
        
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int findMiddle(node* head)
{
    int len=getLen(head);
    int ans=len/2;
    int cnt=0;
    node* temp=head;
    while(cnt<ans)
    {
        temp=temp->next;
        cnt++;
    }
    return temp->data;    
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
    cout<<"Length: "<<getLen(head);
    cout<<"The Middle Element is: "<<findMiddle(head);
    return 0;
return 0;
}




