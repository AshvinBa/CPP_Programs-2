/*
Largest subarray with 0 sum

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

*/


#include<iostream>
using namespace std;

int sub(int arr[],int n)
{
    int count=0,ans=0;
    int i=0,j=0;
    ans=arr[0];
    while(i<n)
    {
        if(ans==0)
        {
            return count;
        }
        else if(ans<0)
        {
            ans=ans+arr[i];
            i++;
            count++;
        }
        else if(ans>0)
        {
            ans=ans-arr[j];
            j++;
            count--;
        }
    }
    return -1;
}

int main(){
    int n = 8;
    int arr[] = {15,-2,2,-8,1,7,10,23};
    cout<<sub(arr,n);
return 0;
}






