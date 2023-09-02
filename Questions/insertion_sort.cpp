/*
Insertion Sort
The task is to complete the insert() function which is used to implement Insertion Sort.

Example 1:
Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9

Example 2:
Input:
N = 10
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output:
1 2 3 4 5 6 7 8 9 10

*/

#include<iostream>
using namespace std;

void insert(int arr[], int i)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(temp<arr[j])
            {
                arr[i]=arr[j];
                i--;
            }
            else
            {
                break;
            }
        }
        arr[i]=temp;
    }
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
            insert(arr,i);
        }
    }

int main(){
    int arr[]={5,1,3,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Answer: ";
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}