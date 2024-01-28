/*
Get minimum element from stack
You are given N elements and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

Example 1:
Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query 
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack 
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2 
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1
Your Task:
You are required to complete the three methods push() which takes one argument an integer 'x' to be pushed into the stack, pop() which returns an integer popped out from the stack, and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity: O(1) for all the 3 methods.
Expected Auxiliary Space: O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    
    public:
    int minEle;
    stack<int> s,s2;
       /*returns min element from stack*/
       int getMin(){
           if(s2.empty())
           {
               return -1;
           }
           return s2.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty())
           {
               return -1;
           }
           if(s.top()==s2.top())
           {
               s2.pop();
           }
           int n=s.top();
           s.pop();
           return n;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s2.empty() || x <= s2.top())
           {
               s2.push(x);
           }
           s.push(x);
       }
};

int main()
 {
    long long t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
        int q;
        cout<<"enter the number of query want to insert: ";
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cout<< "\nPress-1 PUSH\nPress-2 POP\nPress-3 GETMIN: "<<endl;
           cout<<"Enter the values: ";
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cout<<"\nEnter the value: ";
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<"The poped element is: ";
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<"\nMinimum Element is: ";
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
