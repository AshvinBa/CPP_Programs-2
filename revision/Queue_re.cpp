#include<iostream>
using namespace std;

int queue[50000],front=-1,rear=-1,size=10;

void push(int n)
{
    if(rear==size)
    {
        cout<<"The Queue is Full.";
    }
    else
    {
        front=0;
        rear++;
        queue[rear]=n;
        cout<<"The element iserted is: "<<queue[rear]<<endl;
    }
}

void pop()
{
    if(front>=rear || rear==-1)
    {
        cout<<"The Queue is Empty.";
    }
    else
    {
        int ans=queue[front];
        cout<<"The Deleted digit is: "<<ans<<endl;
        front++;
    }
}

void top()
{
    if(rear==-1 || front>=rear)
    {
        cout<<"The Queue is Empty.";
    }
    else
    {
        int ans=queue[rear];
        cout<<"The Element at top is: "<<ans<<endl;
    }
}


void display()
{
    if(front>=rear || rear==-1)
    {
        cout<<"The queue is Empty.";
    }
    else
    {
        cout<<"The Queue is: ";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    pop();
    display();
    pop();
    pop();
    display();    
    top();
    
return 0;
}