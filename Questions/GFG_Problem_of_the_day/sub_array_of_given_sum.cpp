/*
Subarray with given sum

Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s==0)return {-1};
        long long sum=0;
        int i=0,j=0;
        while(j<n)
        {
            while(sum<s && j<n)
            {
                sum+=arr[j];
                j++;
            }
            if(sum==s)
            return {i+1,j};
            
            while(sum>s && i<j)
            {
                sum-=arr[i];
                i++;
            }
            if(sum==s)
            return {i+1,j};
        }
        return {-1};
    }

int main()
{
    vector<int>arr={1,2,3,7,5};
    int n=arr.size();
    long long s=12;
    vector<int>ans=subarraySum(arr,n,s);
    cout<<"Answer: ";
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}














