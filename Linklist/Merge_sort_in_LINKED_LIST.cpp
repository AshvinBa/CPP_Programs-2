#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *left, Node *right)
    {
        if (left == NULL)
        {
            return right;
        }

        if (right == NULL)
        {
            return left;
        }

        Node *ans = new Node(-1);
        Node *temp = ans;

        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        return ans;
    }

    Node *findmid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast->next != NULL && fast == NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *mid = findmid(head);

        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        Node *result = merge(left, right);

        return result;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    struct Node *a = NULL;
    long n, tmp;
    cout << "Enter the limit: ";
    cin >> n;
    cout << "\nEnter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
    return 0;
}