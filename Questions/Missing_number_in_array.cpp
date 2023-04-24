/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int missing_no(int arr[],int n)
{
    int sum1=n*(n+1)/2;
    int sum2=0;
    
    for(int i=0;i<n-1;i++)
    {
        sum2+=arr[i];
    }
    int diff=sum1-sum2;

    return diff;
}

int main(){
    int arr[]={1,2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=missing_no(arr,n);
    cout<<"Answer: "<<x<<endl;

return 0;
}