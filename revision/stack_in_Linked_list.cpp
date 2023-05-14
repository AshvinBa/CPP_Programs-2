#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};
class Queue
{
    int size;
    Node* front;
    Node* rear;

    public:

    Queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }

    void push(int n)
    {
        Node* newNode=new Node();
        newNode->val=n;
        newNode->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=newNode;
            rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
        cout<<"\nThe Element inserted: "<<n<<endl;
        size++;
    }

    void pop()
    {
        if(front==NULL)
        {
            cout<<"Queue is Empty.";
        }
        Node* temp=front;
        front=front->next;
        delete temp;
        size--;
                
    }

    void display()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty.";
        }
        
            cout<<"The Element is: \n";
            Node* temp=front;
            while(temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        cout<<endl;
    }

};


int main(){
    Queue q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
return 0;
}





