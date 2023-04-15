#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s, int n,int current)
{
   if (s.empty() || current == n)
    return;
 
   int x = s.top();
   s.pop();
 
   deleteMiddle(s, n, current+1);
 
   if (current != n/2)
    s.push(x);
}
void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
    int cnt=0;
    deleteMiddle(s,sizeOfStack,cnt);
    }

int main()
{
    stack<int>s;
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    cout<<"Enter the stack values: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        s.push(ele);
    }
    
    deleteMid(s,n);
    
    cout<<"Answer: ";
    while(!s.empty())
    {
        int ct=s.top();
        s.pop();
        cout<<ct<<" ";
    }

return 0;
}



/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&s,int cnt,int n)
{
    if(cnt==n/2)
    {
        s.pop();
        return;
    }

    int num=s.top();
    s.pop();

    solve(s,cnt+1,n);
    
    s.push(num);
}

void pop_middle(stack<int>&s,int n)
{
    int cnt=0;
    solve(s,cnt,n);
}

int main()
{
    stack<int>s;
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    cout<<"Enter the stack values: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        s.push(ele);
    }
    
    pop_middle(s,n);
    
    cout<<"Answer: ";
    while(!s.empty())
    {
        int ct=s.top();
        s.pop();
        cout<<ct<<" ";
    }

return 0;
}
*/