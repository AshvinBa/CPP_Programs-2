/*
Bitonic Point
Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.
Note: If the array is increasing then just print the last element will be the maximum value.

Example 1:
Input:
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.

Example 2:
Input:
n = 5
arr[] = {1, 45, 47, 50, 5}
Output: 50
Explanation: Maximum element is 50.
*/

#include <iostream>
using namespace std;

int findMaximum(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    int ans = 0;

    while (s < e)
    {

        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = (s + e) / 2;
    }
    return arr[s];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Answer: " << findMaximum(arr, n);
    return 0;
}