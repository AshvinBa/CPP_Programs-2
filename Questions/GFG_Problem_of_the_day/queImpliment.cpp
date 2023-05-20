#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

int main()
{
        MyQueue *sq = new MyQueue();

        int Q;
        int QueryType=0;
        cout<<"Enter the query 1 or 2: ";
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cout<<"Enter the value: ";
            cin>>a;
            sq->push(a);
        }
        else if(QueryType==2)
        {
            cout<<"\nDeleted Element is: "<<sq->pop()<<" ";
        }
}
        
void MyQueue :: push(int x)
{
    if(rear==100005)
    {
        cout<<"The queue is full.";
    }
    else
    {
        arr[rear]=x;
        cout<<"Element is inserted: "<<arr[rear]<<" ";
        rear++;
    }
}

int MyQueue :: pop()
{       
    if(front==rear)
    {
        return -1;
    }
    else
    {
        int ans=arr[front];
        arr[front]=-1;
        front++;
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        return ans;
    }
}
