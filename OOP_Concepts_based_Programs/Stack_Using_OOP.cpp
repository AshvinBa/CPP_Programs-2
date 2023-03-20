/*
parameterized constructors = The parameterized constructors can take argument to initialize an object when it created . The PArameterized constructors can be called implicity or explicity. 
 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack         /* Declairation of Class */
{
public:
    int *arr;      /* dynamic memory allocation for arr */
    int top;       /* set pointer for stack */
    int size;      /* size of stack */

    Stack(int size)      /* set size by using Parameterised constructor*/
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele)    /* Function for push an element inside stack. */
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = ele;
        }
        else
        {
            cout << "Stack is overflow.";
        }
    }
    void pop()  /*function for pop/Deleat an element. */
    {
        if (top >= 0)
        {
            cout << "Your poped element: " << arr[top] << endl;
            top--;
        }
        else
        {
            cout << "Stack is underflow.";
        }
    }
    int peek()    /*The fuction use to know peak elenent. */
    {
        if (top >= 0)
        {
            cout << "Peek Elenent: " << arr[top];
        }
        else
        {
            cout << "Stack is Empty.";
        }
    }
    bool isEmpty()  /* check Stack is Empty or not.*/
    {
        if (top > -1)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    int Display()   /* To display the element is Stack. */
    {
        if (top >= 0)
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            cout << "Stack is Empty.";
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of Stack: ";
    cin >> n;
    int s;
    Stack st(n);   /* created object of parameterize constructor and argument also passed.*/
    int ele;
    do        /* do while loop for oprate all the operations.*/
    {
        cout << "\n"
             << endl;
        cout << "     ***OPERATION***" << endl;
        cout << "\t1)PUSH" << endl;
        cout << "\t2)POP" << endl;
        cout << "\t3)PEAK" << endl;
        cout << "\t4)EMPTY" << endl;
        cout << "\t5)DISPLAY" << endl;
        cout << "\t6)EXIT" << endl;
        cout << "\nEnter any operation: ";
        cin >> s;
        switch (s)    /* switch case to select operation one by one.*/
        {
        case 1:
        {
            cout << "Enter the integer: ";
            cin >> ele;
            st.push(ele);
        }
        break;

        case 2:
        {
            st.pop();
        }
        break;

        case 3:
        {
            st.peek();
        }
        break;

        case 4:
        {
            cout << st.isEmpty();
        }
        break;

        case 5:
        {
            st.Display();
        }
        break;

        case 6:
        {
            cout << "Exit.";
        }
        }
    } 
    while (s != 6);
    
    return 0;
}
