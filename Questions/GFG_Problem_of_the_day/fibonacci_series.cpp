/*
Print first n Fibonacci Numbers
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:
Input:
N = 5
Output: 1 1 2 3 5

Example 2:
Input:
N = 7
Output: 1 1 2 3 5 8 13
Your Task:
Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used to store and return the answer for printing purpose.
Constraints:
1<= N <=84
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
    vector<long long> printFibb(int n) 
    {
        vector<long long >ans;
        long long int a=1,b=1;
        
        if(n>=1)
        ans.push_back(1);
        
        if(n>=2)
        ans.push_back(1);
        
        for(long long int i=2;i<n;i++)
        {
            
            ans.push_back(a+b);
            long long int c=a+b;
            a=b;
            b=c;
        }
        return ans;
    }
int main(){
    int n;
    cout<<"Enter the values of n: ";
    cin>>n;
    vector<long long>ans=printFibb(n);
    cout<<"The fibbo is: ";
    cout<<endl;
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }

return 0;
}