#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free from node with data: " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    // new node created
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int ele)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(head, ele);
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
        insertAttail(tail, ele);
        return;
    }

    Node *nodeToInsert = new Node(ele);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->next = NULL;
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
    int s;
    cout << "Enter the Head value: ";
    cin >> s;
    Node *node1 = new Node(s);
    Node *head = node1;
    Node *tail = node1;

    int n;
    do
    {
        cout << "\n   ***OPERATIONS IN LINKLIST***";
        cout << "\n\t1) Insertion at Head.";
        cout << "\n\t2) Insertion at Tail.";
        cout << "\n\t3) Insertion at Position.";
        cout << "\n\t4) Deletion at Position.";
        cout << "\n\t5) Display Element: ";
        cout << "\n\t6) Exit.";
        cout << "\n\tEnter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int x;
            cout << "\nEnter the element: ";
            cin >> x;
            insertAtHead(head, x);
        }
        break;

        case 2:
        {
            int x;
            cout << "\nEnter the element: ";
            cin >> x;
            insertAttail(tail, x);
        }
        break;

        case 3:
        {
            int ele;
            cout << "\nEnter the element: ";
            cin >> ele;
            int index;
            cout << " Enter the index: ";
            cin >> index;
            insertAtPosition(head, tail, index, ele);
        }
        break;

        case 4:
        {
            int x;
            cout << "\nEnter the position for deleat: ";
            cin >> x;
            deleteNode(x, head);
        }
        break;

        case 5:
        {
            print(head);
        }
        break;

        case 6:
        {
            cout << "Exit.";
        }
        }
    }
    while (n != 6);
    
    return 0;
}