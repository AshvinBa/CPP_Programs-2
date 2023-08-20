/*
Number of occurrence

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:
Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.

Example 2:
Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int occurence(int arr[],int n,int x)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        if(i.first==x)
        return i.second;
    }
    return 0;
}

int main(){
    int arr[]={1,1,2,2,2,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=2;
    cout<<occurence(arr,n,x);
return 0;
}