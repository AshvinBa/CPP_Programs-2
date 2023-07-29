#include <iostream>
using namespace std;

int stack[500], top = -1, size = 10;

void push(int val)
{
    if (top == size)
    {
        cout << "\tThe stack is Empty.";
        return;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "\tThe stack is Empty.";
        return;
    }
    else
    {
        int del = stack[top];
        cout << "\tDeleted Element is: " << del;
        top--;
    }
}

void isEmpty()
{
    if (top == -1)
    {
        cout << "\tThe stack is Empty.";
    }
    else
    {
        cout << "\tStack is not Empty.";
    }
}

void top_Element()
{
    if (top == -1)
    {
        cout << "\tThe stack is Empty.";
    }
    else
    {
        int val = stack[top];
        cout << "\tThe top Element is: " << val;
    }
}

void display()
{
    if(top==-1)
    {
        cout<<"\tThe stack is Empty.";
    }
    else{

        cout<<"\tThe Elements are: ";
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
    }
}

int main()
{
    int s;
    do
    {
        cout << "\n\n\t***Operation in Stack***" << endl;
        cout << "\t 1)Push Operation." << endl;
        cout << "\t 2)Pop Operation." << endl;
        cout << "\t 3)Top Operation." << endl;
        cout << "\t 4)Is Empty Operation." << endl;
        cout << "\t 5)Print the Elements." <<endl;
        cout << "\t 6)Exit" << endl;
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
            top_Element();
        }
        break;

        case 4:
        {
            isEmpty();
        }
        break;

        case 5:
        {
            display();
        }
        break;

        case 6:
        {
            cout<<"\n\tExit.";
        }
        break;

        }
    }
    while (s < 6);
    return 0;
}