#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node of data: " << val << endl;
    }
};
int getLen(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int search(Node *head, int d)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == d)
        {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAttail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAttail(head, tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&tail, Node *&head, int position)
{
    Node *temp = head;
    if (position == 1)
    {
        // memory manage for head
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if (temp->next == NULL)
    {
        // memory manag for tail
        Node *temp = tail;
        temp->next->prev = NULL;
        temp->next = NULL;
        tail = temp->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{                              

    Node *head = NULL;
    Node *tail = NULL;
    int s;
    
    do
    {
        cout << "\n\n   ***Operations in Double Link_List*** ";
        cout << "\n\t1) Insert from start.";
        cout << "\n\t2) Insert from End.";
        cout << "\n\t3) Insert at Specific Position.";
        cout << "\n\t4) Delete Element by giving Position.";
        cout << "\n\t5) Search Element in Link list.";
        cout << "\n\t6) Display the Link list.";
        cout << "\n\t7) Exit.";
        cout << "\n\tEnter Your choise: ";
        cin >> s;
    
        switch (s)
        {
        case 1:
        {
            int x;
            cout << "Enter the element: ";
            cin >> x;
            insertAtHead(head, tail, x);
        }
        break;

        case 2:
        {
            int x;
            cout << "Enter the element: ";
            cin >> x;
            insertAttail(head, tail, x);
        }
        break;

        case 3:
        {
            int x, pos;
            cout << "Enter the element: ";
            cin >> x;
            cout << "Enter the position: ";
            cin >> pos;
            insertAtPosition(tail, head, pos, x);
        }
        break;

        case 4:
        {
            int pos;
            cout << "Enter the Position: ";
            cin >> pos;
            deleteNode(tail, head, pos);
            print(head);
        }
        break;

        case 5:
        {
            int x;
            cout << "Enter the number for search: ";
            cin >> x;
            int j = search(head, x);
            if (j == 1)
            {
                cout << "\nFound.";
            }
            else
            {
                cout << "\nNot Found.";
            }
        }
        break;

        case 6:
        {
            cout << "Elements are: ";
            print(head);
        }
        break;

        case 7:
        {
            cout << "Exit.";
        }
        break;
        }
    }
    
    while (s != 7);
    
    return 0;
}
