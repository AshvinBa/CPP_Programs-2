/*
Kadane's Algorithm

Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.


Example 1:
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which
is a contiguous subarray.

Example 2:
Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1
of element (-1)


*/

#include <iostream>
using namespace std;

long maxSubarraySum(int arr[], int n)
{
    long long int sum = 0;
    long long int i = 0;
    long long int mini = 0;
    long long int maxi = arr[i];

    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        maxi = max(sum - mini, maxi);
        mini = min(sum, mini);
    }
    return maxi;
}
int main()
{
    int n;
    int arr[] = {1, -1, 5, 1, 5, 8, -1, -6};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nAnswer: " << func(n, arr);
    return 0;

    return 0;
}