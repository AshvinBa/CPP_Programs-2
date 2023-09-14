/*
Find Missing And Repeating

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Example 2:
Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) 
{    
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]<0)
        {
            a=abs(arr[i]);
        }
        else
        {
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            b=i+1;
            break;
        }
    }
    
    return {a,b}; 
}
int main(){
    vector<int>arr{2,2};
    int n=arr.size();
    vector<int> ans=findTwoElement(arr,n);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}