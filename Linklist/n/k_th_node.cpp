#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cout<<"Enter how many time want Operation: ";
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cout<<"Enter the limit of the Numbers: ";
        cin>>n;
        cout<<"Enter the values: ";
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}

/*
int fractional_node(struct Node *head, int k)
{
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    
    int n=cnt/k;
    cnt=1;
    temp=head;
    
    while( cnt < n)
    {
        temp=temp->next;
        cnt++;
    }
    return temp->data;
}

*/
int fractional_node(struct Node *head, int k)

{
    int 


}










