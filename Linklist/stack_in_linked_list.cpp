#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
class stack
{
    Node *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int n)
    {
        Node *temp = new Node();
        temp->val = n;
        temp->next = head;
        head = temp;
        cout << endl
             << "Element " << n << " is inserted.";
        size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << endl
                 << "Stack is Empty.";
        }

        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        cout << endl
             << "value is poped from the stack.";
        size--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << endl
                 << "No element in stack. ";
        }
        else
        {
            cout << endl
                 << "The Top element is: ";
            return head->val;
        }
    }

    int size1()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            cout << endl
                 << "size of the stack is: ";
            return size;
        }
    }

    int isEmpty()
    {
        if (head == NULL)
        {
            cout << endl
                 << "The stack is empty.";
        }
        else
        {
            cout << endl
                 << "Not Empty.";
        }
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    stack st;
    int n;
    do
    {

        cout << "\n\n  ***Stack Operations In Linked List***" << endl;
        cout << "     Press-1 PUSH." << endl;
        cout << "     Press-2 POP." << endl;
        cout << "     Press-3 SIZE." << endl;
        cout << "     Press-4 TOP." << endl;
        cout << "     Press-5 EMPTY OR NOT." << endl;
        cout << "     Press-6 PRINT." << endl;
        cout << "     Press-7 EXIT." << endl;
        cout << "     Enter the Choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            int integer;
            cout << endl
                 << "Enter the element: ";
            cin >> integer;
            st.push(integer);
        }
        break;

        case 2:
        {
            st.pop();
        }
        break;

        case 3:
        {
            cout << st.size1();
        }
        break;

        case 4:
        {
            cout << st.top();
        }
        break;

        case 5:
        {
            st.isEmpty();
        }
        break;

        case 6:
        {
            st.print();
        }
        break;
        }
    } while (n != 7);
    return 0;
}
