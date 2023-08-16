/*
Move all zeroes to end of array

Given an array arr[] of N positive integers. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements.

Example 1:
Input:
N = 5
Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0
Explanation: The non-zero elements
preserve their order while the 0
elements are moved to the right.

Example 2:
Input:
N = 4
Arr[] = {0, 0, 0, 4}
Output: 4 0 0 0
Explanation: 4 is the only non-zero
element and it gets moved to the left.
*/
#include<iostream>
using namespace std;

void pushZerosToEnd(int arr[], int n) 
{
	int j=0;
	for(int i=0;i<n;i++)
    {
	    if(arr[i]!=0 && arr[j]==0)
	    {
            int temp=arr[i];
	        arr[i]=arr[j];
	        arr[j]=temp;
	    }
        if(arr[j]!=0)
	    {
	        j++;
        }
    }
}
int main(){
    int arr[]={4,5,6,0,0,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    pushZerosToEnd(arr,n);
    cout<<"\nAnswer: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}