/*
Searching in an array where adjacent differ by at most k
A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple elements exist, and return the first occurrence of the key.

Example 1:
Input : arr[ ] = {4, 5, 6, 7, 6}, K = 1 
        and X = 6
Output : 2
Explanation:
In an array arr 6 is present at index 2.
So, return 2.

Example 2:
Input : arr[ ] = {20 40 50}, K = 20 
        and X = 70
Output :  -1 

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    for(int i=0;i<n;i++)
    { 
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={4,5,6,7,8,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=1;
    int x=7;
    cout<<"\nAnswer: "<<search(arr,n,x,k); 
return 0;
}