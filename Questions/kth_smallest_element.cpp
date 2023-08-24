/*
Kth smallest element

Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
Note :-  l and r denotes the starting and ending index of the array.

Example 1:
Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.

Example 2:
Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

 int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int>p;
        int n=r-l+1;
        
        for(int i=0;i<k;i++)
        {
            p.push(arr[i]);
        }
        
        for(int i=k;i<n;i++)
        {
            if(arr[i]<p.top())
            {
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }

int main(){
    int arr[]={7,10,4,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<"The Kth smallest is: "<<kthSmallest(arr,0,n-1,k);
return 0;
}





