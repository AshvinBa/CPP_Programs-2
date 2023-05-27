#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

int main()
{

    MyStack *sq = new MyStack();

    int QueryType = 0;
    cout << "Enter the 1 for push and 2 for pop: ";
    cin >> QueryType;
    if (QueryType == 1)
    {
        int a;
        cout<<"Enter the number:"; 
        cin >> a;
        sq->push(a);
    }
    else if (QueryType == 2)
    {
        cout << sq->pop() << " ";
    }

    cout << endl;
}

void MyStack ::push(int x)
{
    if (top == 1000)
    {
        cout << "Stack is Full.";
    }
    top++;
    arr[top] = x;
}

int MyStack ::pop()
{
    if (top == -1)
    {
        return -1;
    }
    int ans = arr[top];
    top--;
    return ans;
}
