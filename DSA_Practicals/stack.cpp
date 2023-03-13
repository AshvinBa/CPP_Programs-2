#include <iostream>
using namespace std;
int stack[200], n = 10, top = -1;

int push()
{
    int ele;
    cout << "Enter the element: ";
    cin >> ele;

    if (top == n - 1)
    {
        cout << "Stack is Full.";
    }
    else
    {
        if (top == -1)
            top = 0;
        stack[top] = ele;
        top++;
    }
}

int pop()
{
    if (top < 0)
    {
        cout << "Stack is Underflow.";
    }
    else
    {
        top--;
    }
}

int display()
{
    if (top < 0)
    {
        cout << "Stack is Empty.";
    }
    for (int i = 0; i < top; i++)
    {
        cout << stack[i] << " ";
    }
}

int isEmpty()
{
    if (top < 0)
    {
        cout << "Stack is Empty.";
    }
    else
    {
        cout << "Stack is Not Empty.";
    }
}

int main()
{
    int s;
    cout << "Press 1-INSERTION." << endl;
    cout << "Press 2-DELETION." << endl;
    cout << "Press 3-DISPLAY." << endl;
    cout << "Press 4-EMPTY or NOT." << endl;
    cout << "Press 5-EXIT." << endl;

    do
    {

        cout << "\n\nEnter Your choice: ";
        cin >> s;

        switch (s)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            cout << "Exit.";
            break;

        default:
            cout << "You Entered Wrong choice.";
        }
    }

    while (s != 5);
    return 0;
}
