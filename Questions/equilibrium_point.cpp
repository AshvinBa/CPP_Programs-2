/*
Equilibrium Point
Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Retun the index of Equilibrium point. (1-based index)

Example 1:
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation:  
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2). 
 

Example 2:
Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.
*/

#include<iostream>
using namespace std;

int equilibrium(int arr[],int n)
{

    int left[n],right[n];
    
    left[0]=0;//putting 0 at the first position of left array.
    right[n-1]=0;//putting 0 at the last position of the right array.

    int a;
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]+arr[i-1];
    }
    for(int j=n-2;j>=0;j--)
    {
        right[j]=right[j+1]+arr[j+1];
    }

    for(int i=0;i<n;i++)
    {
        if(left[i]==right[i])
        {
            return i+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,3,5,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nPosition is: "<<equilibrium(arr,n);
return 0;
}