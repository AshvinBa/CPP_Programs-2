/*
Find Transition Point

Given a sorted array containing only 0s and 1s, find the transition point, i.e., the first index where 1 was observed, and before that, only 0 was observed.

Example 1:
Input:
N = 5
arr[] = {0,0,0,1,1}
Output: 3
Explanation: index 3 is the transition
point where 1 begins.

Example 2:
Input:
N = 4
arr[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",
the answer is -1.
Your Task:
You don't need to read input or print anything. The task is to complete the function transitionPoint() that takes array arr and N as input parameters and returns the 0-based index of the position where 0 ends and 1 begins. If array does not have any 1, return -1. If array does not have any 0, return 0.

Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
0 ≤ arr[i] ≤ 1

*/

#include <iostream>
using namespace std;

int transitionPoint(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] == 1 and arr[mid - 1] == 0)
        {
            return mid;
        }
        else if (arr[mid] == 1 and arr[mid + 1] == 1)
        {
            e = mid - 1;
        }
        else if (arr[mid] == 0)
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\n Index: " << transitionPoint(arr, n);
    return 0;
}