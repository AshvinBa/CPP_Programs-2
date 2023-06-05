/*
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

Example 1:
Input: N = 1
Output: YES
Explanation:1 is equal to 2 
raised to 0 (20 = 1).

Example 2:
Input: N = 98
Output: NO
Explanation: 98 cannot be obtained
by any power of 2.

*/

#include<math.h>
#include<iostream>
using namespace std;

bool isPowerofTwo(long long n){
        if(n==0)
        {
            return 0;
        }
        if((n&(n-1))==0)
        {
            return 1;
        }
        else {
            return 0;
        }
    }

int main(){
    long long int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ans=isPowerofTwo(n);
    if(ans)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}