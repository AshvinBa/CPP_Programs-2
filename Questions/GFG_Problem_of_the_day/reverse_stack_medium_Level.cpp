/*
Reverse a Stack
You are given a stack St. You have to reverse the stack using recursion.

Example 1:
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.

Example 2:
Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void insert(stack<int>&s,int top)
    {
        if(s.empty())
        {
        s.push(top);
        return;
        }
        
        int newtop=s.top();
        s.pop();
        insert(s,top);
        s.push(newtop);
    }

    void Reverse(stack<int> &s)
    {
        if(s.empty())
        return;
        
        int top=s.top();
        s.pop();
        Reverse(s);
        insert(s,top);
    }


int main(){
    stack<int>s;
    cout<<"Enter the values: ";
    for(int i=1;i<=5;i++)
    {
        cin>>i;
        s.push(i);
    }
    cout<<"Reverse: ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}

/*
OUTPUT
Enter the values: 
1
2
3
4
5
Reverse: 5 4 3 2 1 
*/