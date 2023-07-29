#include <iostream>
using namespace std;

char stack[20];
int top = -1;

void push(char x) // push function work as similar as stack.
{
    stack[++top] = x;
}

char pop() // pop function work as similar as stack.
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x) // priority function work as per priority.
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '/' || x == '*')
    {
        return 2;
    }
}

int main()
{
    char exp[20];
    char *e, x;

    cout << "Enter the Expression: ";
    cin >> exp;

    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e)) // check the value is numeric or operator.
        {
            cout << *e;
        }
        else if (*e == '(') // it push open bracket in stack.
        {
            push(*e);
        }
        else if (*e == ')') // it check close bracket.
        {
            while ((x = pop()) != '(') // it pop top values up to closing bracket.
                cout << x;
        }
        else
        {
            while (priority(stack[top]) >= priority(*e)) // it check the priority of the operators.
                cout << pop();

            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        cout << pop();
    }

    return 0;
}
