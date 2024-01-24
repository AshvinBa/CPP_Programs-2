/*
Sort a stack
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    cout<<"Sorted Values: ";
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cout<<"Enter the number of test cases: ";
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
    cout<<"Enter the size: ";
	cin>>n;
    cout<<"Enter the values: ";
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}

void sorting(vector<int>&arr,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(n-i);j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void SortedStack :: sort()
{
    vector<int>arr;
    
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        arr.push_back(x);
    }
    
    int n=arr.size();

    sorting(arr,n);        

    for(int i=n-1;i>=0;i--)
    {
        s.push(arr[i]);
    }
}