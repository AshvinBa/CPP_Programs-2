#include<iostream>
using namespace std;

int queue[100],rear=-1,front=-1,size=10;

void push(int val)
{
    if(rear==-1 && front==-1)
    {
        rear=front=0;
        queue[rear]=val;
    }
    else if((rear+1)%size==front)
    {
        cout<<"The Queue is Full.";
        return;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=val;
    }
}


void pop()
{
    if(front>rear)
    {
        cout<<"\tThe Circular Queue is Empty.";
        return;
    }
    else
    {
        int val=queue[front];
        front=(front+1)%size;
        cout<<"\tThe Deleted value in Queue: "<<val;
    }
}

void display()
{
    if(front==rear)
    {
        cout<<"\tThe Queue is Empty.";
        return;
    }
    else
    {
        cout<<"\nThe Value of Queue is: ";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
    }
}

int main(){

        int s;
    do
    {
        cout << "\n\n\t***Operation in Queue***" << endl;
        cout << "\t 1)Push Operation." << endl;
        cout << "\t 2)Pop Operation." << endl;
        cout << "\t 3)Print the Elements." <<endl;
        cout << "\t 4)Exit" << endl;
        cout << "\n\tChooes Operation: ";
        cin >> s;
        switch (s)
        {
        case 1:
        {
            int val;
            cout << "\tEnter the digit: ";
            cin >> val;
            push(val);
        }
        break;

        case 2:
        {
            pop();
        }
        break;

        case 3:
        {
            display();
        }
        break;

        case 4:
        {
            cout<<"\n\tExit.";
        }
        break;

        }
    }
    while (s < 4);

return 0;
}