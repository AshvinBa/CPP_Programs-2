/*
Merge two sorted linked lists

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.


Example 1:

Input:
N = 4, M = 3
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

Node *sortedMerge(Node *a, Node *b);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cout << "How many time wants this procedure: ";
    cin >> t;
    while (t--)
    {
        int n, m;
        cout << "Enter the limit of first and second Linked List: ";
        cin >> n >> m;

        int data;
        cout << "\nEnter the values for first Linked List: ";
        cin >> data;
        Node *head1 = new Node(data);
        Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cout << "\nEnter the values for second Linked List: ";
        cin >> data;
        Node *head2 = new Node(data);
        Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

Node *solve(Node *head1, Node *head2)
{
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    Node *curr1 = head1;
    Node *next1 = head1->next;
    Node *curr2 = head2;
    Node *next2 = head2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}
