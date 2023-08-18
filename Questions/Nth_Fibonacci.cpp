/*
Nth Fibonacci Number

Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.
Example 1:
Input: 
n = 2
Output: 
1 
Explanation: 
1 is the 2nd number of fibonacci series.

Example 2:
Input: 
n = 5
Output: 
5
Explanation: 
5 is the 5th number of fibonacci series
*/

#include<iostream>
using namespace std;

int nthFibonacci(int n){
        int x,y;
        x=y=1;
        const int mod=1e9+7; 
        for(int i=3;i<n+1;i++)
        {
            x=(x+y)%mod;
            swap(x,y);
        }
        return y;
    }
int main()
{
    int n=7;
    cout<<nthFibonacci(n);
}