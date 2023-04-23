#include <iostream>
using namespace std;

class Node
{
public:

    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Deleted Element is: " << val << endl;
    }
};

void insertNode(Node *&tail, int ele, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != ele)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "The List Is Empty." << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    }
    while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is Empty,please check again";
        return;
    }
    else
    {
        // non-Empty.
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;

    int s;
    do
    {
        cout << "\n\n   ***Operations in Double Link_List*** ";
        cout << "\n\t1) Insert an Element.";
        cout << "\n\t2) Deleat Element.";
        cout << "\n\t3) Display the Link list.";
        cout << "\n\t4) Exit.";
        cout << "\n\tEnter Your choise: ";
        cin >> s;
        switch (s)
        {
        case 1:
        {
            int x, ele;
            cout << "Enter the digit want to insert: ";
            cin >> x;
            cout << "Enter the previous digit want to enter: ";
            cin >> ele;
            insertNode(tail, ele, x);
        }
        break;

        case 2:
        {
            int x;
            cout << "Enter the element want to delete: ";
            cin >> x;
            deleteNode(tail, x);
            print(tail);
        }
        break;

        case 3:
        {
            cout << "\nThe elements: ";
            print(tail);
        }
        break;

        case 4:
        {
            cout << "Exit.";
        }
        break;
        }
    }

    while (s != 4);

    return 0;
}