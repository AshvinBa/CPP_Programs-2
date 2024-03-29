/*
Merge Sort

Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:
Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9

Example 2:
Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10

Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

Expected Time Complexity: O(nlogn) 
Expected Auxiliary Space: O(n)
Constraints:
1 <= N <= 105
1 <= arr[i] <= 105

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int s, int mid, int e)
    {
        int len1=mid-s+1;
        int len2=e-mid;
        
        int *first=new int[len1];
        int *second=new int[len2];
        
        int mainArrayIndex=s;
        for(int i=0;i<len1;i++)
        {
            first[i]=arr[mainArrayIndex++];
        }
        
        mainArrayIndex=mid+1;
        for(int i=0;i<len2;i++)
        {
            second[i]=arr[mainArrayIndex++];
        }
        
        int index1=0;
        int index2=0;;
        mainArrayIndex=s;
        
        while(index1<len1 && index2<len2)
        {
            if(first[index1]<second[index2])
            {
                arr[mainArrayIndex++]=first[index1++];
            }
            else
            {
                arr[mainArrayIndex++]=second[index2++];
            }
        }
        
        while(index1<len1)
        {
            arr[mainArrayIndex++]=first[index1++];
        }
        while(index2<len2)
        {
            arr[mainArrayIndex++]=second[index2++];
        }
        delete []first;
        delete []second;
    }

    void mergeSort(int arr[], int s, int e)
    {
        if(s>=e)
        return;
        
        int mid=(s+e)/2;
        
        mergeSort(arr,s,mid);
        
        mergeSort(arr,mid+1,e);
        
        merge(arr,s,mid,e);
    }

int main()
{
    int arr[]={4,8,6,2,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    cout<<"The Sorted Array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
} 

