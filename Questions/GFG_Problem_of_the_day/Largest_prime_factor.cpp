/*

Largest prime factor

Given a number N, the task is to find the largest prime factor of that number.
Example 1:
Input:
N = 5
Output:
5
Explanation:
5 has 1 prime factor i.e 5 only.

Example 2:
Input:
N = 24
Output:
3
Explanation:
24 has 2 prime factors 2 and 3 in which 3 is greater.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// approach -1
//TLE
/*
bool isPrime(int n)
    {
        if(n==2 || n==3)
        return true;
        
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            return false;
        }
        return true;
    }

    long long int largestPrimeFactor(int n){
        
        if(isPrime(n))
        return n;
        long long int ans=INT_MIN;
        for(long long int i=2;i<=(n/2);i++)
        {
            if(n%i==0 && isPrime(i)){
            ans=max(ans,i);
            }
        }
        return ans;
    }
*/
long long int largestPrimeFactor(int n)
{
    long long int ans=0;
    long long int i;
    for(i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            if(i>ans)
            {
                ans=i;
            }
            n=n/i;
        }
    } 
    if(n>1)
    {
        if(n>ans)
        {
            ans=n;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    cout<<"Answer: "<<largestPrimeFactor(n);
return 0;
}