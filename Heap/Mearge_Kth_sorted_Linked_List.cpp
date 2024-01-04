/*
Merge K sorted linked lists

Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.
Example 1:
Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.

Example 2:
Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list


*/

#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

class compare{
    public: 
    
    bool operator()(Node* a,Node* b)
    {
        return a->data > b->data;
    }
    
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*,vector<Node*>,compare>minHeap;
        
        if(K==0)
        return NULL;
        
        for(int i=0;i<K;i++)
        {
            if(arr[i]!=NULL)
            {
                minHeap.push(arr[i]);
            }
        }
        
        Node* head=NULL;
        Node* tail=NULL;
        
        while(minHeap.size()>0)
        {
            Node* top=minHeap.top();
            minHeap.pop();
            
            if(top->next!=NULL)
            {
                minHeap.push(top->next);
            }
            
            if(head==NULL)
            {
                head=top;
                tail=top;
            }
            else
            {
                tail->next=top;
                tail=top;
            }
        }
        return head;
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
	   int N;
       cout<<"Enter the size: ";
	   cin>>N;
       struct Node *arr[N];

       for(int j=0;j<N;j++)
        {
           int n;
           cout<<"Enter the size of row: ";
           cin>>n;

           int x;
           cout<<"Enter the values: ";
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

    }
	return 0;
}
