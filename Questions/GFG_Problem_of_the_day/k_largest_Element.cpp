/*
Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order.

Example 1:
Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.

Example 2:
Input:
N = 7, K = 3
Arr[] = {1, 23, 12, 9, 30, 2, 50}
Output: 50 30 23
Explanation: 3 Largest element in the
array are 50, 30 and 23.

*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>kLargest(int arr[],int n,int k)
{
    sort(arr,arr+n);
    vector<int>ans;
    int i=n-1;
    while(k--)
    {
        ans.push_back(arr[i]);
        i--;
    }
    return ans;
}

int main()
{
    int k = 2;
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = kLargest(arr, n, k);
    cout << "\nAnswer: ";
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}

// right solutin for given  all inputs but take more time complexity.

// give the segmentation Fault.

/*
int max(int arr[], int n, int k)
{
    int max = INT16_MIN;
    int index = -1;
    int i = 0;
    for (; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

vector<int> kLargest(int arr[], int n, int k)
{
    int i = 0;
    vector<int> arr1;
    while (k--)
    {
        i = max(arr, n, k);
        arr1.push_back(arr[i]);
        arr[i] = -1;
    }
    return arr1;
}
*/
