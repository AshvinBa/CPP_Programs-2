/*
Queue using two Stacks

Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Note :- If there is no element return -1 as answer while popping.

Example 1:
Input:
5
1 2 1 3 2 1 4 2
Output: 
2 3
Explanation: 
In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue 
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Example 2:
Input:
4
1 2 2 2 1 4

Output: 
2 -1
Explanation: 
In the second testcase 
1 2 the queue will be {2}
2   poped element will be 2 and 
    then the queue will be empty
2   the queue is empty and hence -1
1 4 the queue will be {4}.
Your Task:
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue and pop which returns a integer poped out from other queue(-1 if the queue is empty). The printing is done automatically by the driver code.

Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()  
Expected Auxilliary Space : O(1).

Constraints:
1 <= Q <= 100
1 <= x <= 100
Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

#include<bits/stdc++.h>
using namespace std;
class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cout<<"Enter the testcase: ";
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cout<<"ENter the number of query: ";
        cin>>Q;
        while(Q--)
        {
        int QueryType=0;
        cout<<"Enter the query: ";
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cout<<"Enter the data: ";
            cin>>a;
            sq->push(a);
        }
        else if(QueryType==2)
        {
            cout<<sq->pop()<<" "<<endl;
        }
        }
        cout<<endl;
    }
}

void StackQueue :: push(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    s1.push(x);
    
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }     
}
int StackQueue :: pop()
{
    int ans;
    if(!s1.empty())
    {
        ans=s1.top();
        s1.pop();
    }
    else
    {
        ans=-1;
    }
    return ans;
}
