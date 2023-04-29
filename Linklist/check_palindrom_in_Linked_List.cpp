/*
Check if Linked List is Palindrome

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
*/

// Program

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool checkPalindrom(vector<int>arr)
    {
        int i=0;
        int j=arr.size()-1;
        
        while(i<j)
        {
            if(arr[i]!=arr[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int>arr;
        
        Node* curr=head;
        
        while(curr!=NULL)
        {
            arr.push_back(curr->data);
            curr=curr->next;
        }
        return checkPalindrom(arr);
    }
};

/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
