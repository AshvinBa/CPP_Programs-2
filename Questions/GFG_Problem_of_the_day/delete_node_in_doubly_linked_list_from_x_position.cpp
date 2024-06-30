/*
Delete node in Doubly Linked List

Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  
Explanation: 
After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 2 9
Explanation:

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
2 <= size of the linked list(n) <= 105
1 <= x <= n
1 <= node.data <= 109

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) 
    {
        int cnt=1;
        Node* past=head;
        Node* curr=head->next;
        while(curr!=NULL)
        {
            if(x==1)
            {
                if(past->next==NULL)
                {
                    delete past;
                    return curr;
                }
                else
                {
                    Node* temp=past;
                    past->next=NULL;
                    curr->prev=NULL;
                    delete temp;
                    return curr;
                }
            }
            else if(cnt==x-1)
            {
                if(curr->next!=NULL && curr->prev!=NULL)
                {
                    Node* temp=curr;
                    past->next=curr->next;
                    curr->next->prev=past;
                    delete temp;
                    return head;
                }
                else if(curr->next==NULL)
                {
                    Node* temp=curr;
                    curr->prev=NULL;
                    past->next=NULL;
                    delete temp;
                    return head;
                }
            }
            past=curr;
            curr=curr->next;
            cnt++;
        }
    }
};

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}
