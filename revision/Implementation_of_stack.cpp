#include <iostream>
using namespace std;
class Stack
{
    int top;
    int *arr;
    int size;

public:
    Stack(int n)
    {
        this->size = n;
        top = -1;
        arr = new int[size];
    }
    void push(int ele)
    {
        if (top == size - 1)
        {
            cout<<endl<<"The Stack is Full.";
        }
        else
        {
            top++;
            arr[top]=ele;
        }
    }

    void pop()
    {
        if(top<0)
        {
            cout<<endl<<"Stack is Underflow.";
        }
        else
        {
            cout<<"\nYour Deleted Element: "<<arr[top]<<endl;
            top--;        
        }
    }

    void peek()
    {
        if(top<0)
        {
            cout<<"Stack is Empty.";
        }
        else
        {
            cout<<"The Peek Elelment is: "<<arr[top]<<endl;
        }
    }

    void isEmpty()
    {
        if(top<0)
        {
            cout<<"The Stack is Empty.";            
        }
        else
        {
            cout<<"The stack is Not Empty.";
        }
    }

    int display()
    {
        if(top<0)
        {
            cout<<"The Stack is Empty.";
        }
        else
        {
            cout<<"The elements are: ";
            for(int i=0;i<top;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }
};

int main()
{
    Stack s(1000);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.display();
    s.pop();
    cout<<"\n";
    s.display();
    s.pop();
    cout<<"\n";
    s.isEmpty();
    cout<<"\n";
    s.peek();
    s.display();
    return 0;
}

