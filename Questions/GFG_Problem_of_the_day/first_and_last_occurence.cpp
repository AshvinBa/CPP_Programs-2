/*
First and last occurrences of x
Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

Example 1:
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 

Example 2:
Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).
Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i],x ≤ 109

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstPosition(int arr[],int n,int x)
    {
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(arr[mid]==x)
            {
                ans=mid;
                e=mid-1;
            }
            else if(x<arr[mid])
            {
                e=mid-1;
            }
            else if(x>arr[mid])
            {
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    
    
    
    int SecondPosition(int arr[],int n,int x)
    {
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(arr[mid]==x)
            {
                ans=mid;
                s=mid+1;
            }
            else if(x<arr[mid])
            {
                e=mid-1;
            }
            else if(x>arr[mid])
            {
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        int first=firstPosition(arr,n,x);
        int second=SecondPosition(arr,n,x);
        return {first,second};
    }

int main(){
    int arr[]={1,2,3,4,5,5,5,6,7,8};
    int n=10;
    int x=5;
    vector<int>ans=find(arr,n,x);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}