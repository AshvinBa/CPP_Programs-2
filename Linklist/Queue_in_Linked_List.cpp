#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
class Queue
{
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
        this->size = 0;
    }

    void push(int n)
    {
        Node* temp=new Node();
        temp->val = n;
        temp->next = NULL;
        if(rear==NULL && front==NULL) 
        {
            rear = front = temp;
        }        
        else{
            rear->next=temp;
            rear=temp;
        }
        cout << endl
        << "Element " << n << " is inserted.";
        size++;
    }
    

    void pop()
    { 
        if (front == NULL && rear == NULL)
        {
            
            cout << endl 
                 << "Stack is Empty.";
        }
        Node *temp = front;
        front=front->next;
        delete temp;
        cout << endl
             << "value is poped from the stack.";
        size--;
    }

    int top()
    {
        if (rear == NULL)
        {
            cout << endl
                 << "No element in stack. ";
        }
        else
        {
            cout << endl
                 << "The Top element is: ";
            return rear->val;
        }
    }

    int size1()
    {
        if (rear == NULL)
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
        if (rear == NULL)
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
        if(rear == NULL)
        {
            cout<<"\nQueue is Empty.";
        }

        Node *temp = front;
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
    Queue qe;
    int n;
    do
    {

        cout << "\n\n  ***Queue Operations In Linked List***" << endl;
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
            qe.push(integer);
        }
        break;

        case 2:
        {
            qe.pop();
        }
        break;

        case 3:
        {
            cout << qe.size1();
        }
        break;

        case 4:
        {
            cout << qe.top();
        }
        break;

        case 5:
        {
            qe.isEmpty();
        }
        break;

        case 6:
        {
            qe.print();
        }
        break;
        }
    } while (n != 7);
    return 0;
}