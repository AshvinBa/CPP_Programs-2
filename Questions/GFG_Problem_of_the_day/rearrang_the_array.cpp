/*
Rearrange an array with O(1) extra space
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

Example 1:
Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.

Example 2:
Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation: 
arr[arr[0]] = arr[4] = 3.
arr[arr[1]] = arr[0] = 4.
and so on.

*/

#include<iostream>
using namespace std;

void arrange(long long arr[], int n) {
        
        for(int i=0;i<n;i++)
        {
            arr[i]+=(arr[arr[i]]%n)*(long long)n;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]/=n;
        }
    }
int main(){
    long long arr[]={4,0,2,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Output: ";
    arrange(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}