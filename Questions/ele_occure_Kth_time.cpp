/*
First element to occur k times

Given an array of N integers. Find the first element that occurs at least K number of times.

Example 1:

Input :
N = 7, K = 2
A[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4
Explanation:
Both 7 and 4 occur 2 times. 
But 4 is first that occurs 2 times
As at index = 4, 4 has occurred 
atleast 2 times whereas at index = 6,
7 has occurred atleast 2 times.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstElement(int arr[],int n,int k)
{
    unordered_map<int,int>mp{0};
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]>=k)
        return arr[i];
    }
    return -1;
}

int main(){
    int n = 7, k = 2;
    int arr[] = {1, 7, 4, 3, 4, 8, 7};
    cout<<firstElement(arr,n,k);    
return 0;
}