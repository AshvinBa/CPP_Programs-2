/*
Minimum element in a sorted and rotated array

A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example 1
Input:
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1
Explanation: 1 is the minimum element inthe array.

Example 2
Input:
N = 7
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5
Explanation: Here 5 is the minimum element
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int ans = INT_MAX;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[s] <= arr[mid])
        {
            ans = min(ans, arr[s]);
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
            ans = min(ans, arr[mid]);
        }
        mid = (s + e) / 2;
    }
    return ans;
}

int main()
{
    int n;
    int arr[]={4,5,1,2,3};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The minimum number is: ";
    cout<<findMin(arr,n);
    return 0;
}