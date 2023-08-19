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

Example 2:
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> subarray(int arr[],int n,int s)
{
    long long ans=0;
    int i=0;
    int j=0;
    while(j<n)
    {
        ans+=arr[j];
        while(ans>s && i<j)
        {
            ans-=arr[i];
            i++;
        }
        if(ans==s){
        return {i+1,j+1};
        }
        j++;
    }
    return {-1};
}

int main()
{
    int arr[] = {1, 2, 3, 7, 5};
    int s = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = subarray(arr, n, s);
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}

// TC=O(n).
// vector<int> subarray(int arr[],int n,int s)
// {
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         ans=arr[i];
//         for(int j=i+1;j<n;j++)
//         {
//             ans+=arr[j];
//             if(ans>s)
//             {
//                 break;
//             }
//             if(ans==s)
//             {
//                 return {arr[i],arr[j]};
//             }
//         }
//     }
// }