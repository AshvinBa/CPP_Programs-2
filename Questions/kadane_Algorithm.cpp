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

//Approch 2:
int maxSubarraySum(int arr[], int n)
{
    int sum = 0;
    int maxi = arr[0];

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        maxi = max(sum, maxi);

        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}


//Approch 1: It Pass all the Test Cases of the GFG Questions.
/*
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
*/
int main()
{
    int n;
    int arr[] = {1,2,3,-2,5};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nAnswer: " << maxSubarraySum(arr, n);
    return 0;
}