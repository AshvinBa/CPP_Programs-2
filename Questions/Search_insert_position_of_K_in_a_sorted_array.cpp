/*
Search insert position of K in a sorted array
Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if its present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.

Example 1:
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 5
Output: 2
Explaination: Since 5 is found at index 2 
as Arr[2] = 5, the output is 2.

Example 2:
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 2
Output: 1
Explaination: Since 2 is not present in 
the array but can be inserted at index 1 
to make the array sorted.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int searchInsertK(vector<int>arr, int n, int x)
    {
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        
        while(s<=e)
        {
            if(arr[mid]==x)
            {
                return mid;
            }
            else if(arr[mid]>x)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return s;
    }

int main(){
    vector<int>arr{1,2,3,4,5,6,8,9};
    int n=arr.size();
    int x=7;
    cout<<"Answer: "<<searchInsertK(arr,n,x);
return 0;
}