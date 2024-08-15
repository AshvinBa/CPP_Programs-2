/*
Add 1 to a Linked List Number

You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :
Input: LinkedList: 4->5->6
Output: 457
Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 

Input: LinkedList: 1->2->3
Output: 124 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
  
    Node* reverseList(Node* head)
    {
        Node *prev=NULL, *curr=head, *forward=NULL;
        
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        head=reverseList(head);
        int carry=1;
        Node* temp=head;
        Node* tail=NULL;
        
        while(temp!=NULL && carry==1)
        {
            if(temp->data==9)
            {
                temp->data=0;
            }
            else
            {
                temp->data=temp->data+1;
                carry=0;
            }
            tail=temp;
            temp=temp->next;
        }
        if(carry)
        {
            tail->next=new Node(1);
        }
        head=reverseList(head);
        return head;
    }
};

int main() {
    int t;
    cout<<"Enter the test cases: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        cout<<"Enter the values:" ;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        cout<<"Answer: ";
        printList(head);
    }
    return 0;
}
