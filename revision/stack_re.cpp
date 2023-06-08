#include<iostream>
using namespace std;

int stack[5000],top=-1,size=10;

void push(int n)
{
    if(top==size)
    {
        cout<<"The stack is Full.";
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty.";
    }
    else
    {
        int ans=stack[top];
        top--;
        cout<<"The deleted element is: "<<ans;
    }
}

void top1()
{
    if(top==-1)
    {
        cout<<"The stack is Empty."; 
    }
    else
    {
        int ans=stack[top];
        cout<<"The element on the top is: ";
        cout<<ans;
    }
}

void print()
{
    if(top==-1)
    {
        cout<<"The stack is an Empty.";
    }
    else
    {
        cout<<"The Stack is: ";
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    print();
    pop();
    pop();
    print();
    cout<<endl;
    top1();

return 0;
}