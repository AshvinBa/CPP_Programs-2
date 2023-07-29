#include<iostream>
using namespace std;

int queue[200],rear=0,front=0,size=10;

void push(int val)
{
    if(rear==size)
    {
        cout<<"\tThe Queue is Full.";
        return;
    }
    else
    {
        queue[rear]=val;
        rear++;
    }
}

void pop()
{
    if(front==rear || front==size)
    {
        cout<<"\tThe Queue is Empty.";
        return;
    }
    else
    {
        int val=queue[front];
        front++;
        cout<<"\tThe Deleted element is: "<<val;
    }
}

void display()
{
    if(rear==front)
    {
        cout<<"The Queue is Empty.";
        return;
    }
    else
    {
        cout<<"\tThe Queue Element is: ";
        for(int i=front;i<rear;i++)
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