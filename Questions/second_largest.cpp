/*
Second largest element.

The task is to find the second largest element in the array,the n is the size of array.

Example-1
input:
n=5
arr[]={8,6,4,7,3}
output: 7.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int print2largest(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if ((i == n - 2 || arr[i] < arr[n - 1]) && arr[i] != arr[n - 1])
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int n = 5;
    int arr[] = {8, 2, 3, 7, 6};
    cout << "The Second Largest is: " << print2largest(arr, n);
    return 0;
}