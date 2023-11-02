/*
Minimum distance between two numbers

You are given an array a, of n elements. Find the minimum index based distance between two distinct elements of the array, x and y. Return -1, if either x or y does not exist in the array.

Example 1:
Input:
N = 4
A[] = {1,2,3,2}
x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are
two distances between x and y, which are
1 and 3 out of which the least is 1.

Example 2:
Input:
N = 7
A[] = {86,39,90,67,84,66,62}
x = 42, y = 12
Output: -1
Explanation: x = 42 and y = 12. We return
-1 as x and y don't exist in the array.
Your Task:
Complete the function minDist() which takes the array a, and 3 integers n, x and y as input parameters and returns the minimum distance between x and y in the array. Return -1, if either x or y does not exist in the array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
0 <= a[i], x, y <= 105
x != y


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minDist(int arr[], int n, int x, int y)
{
    int a = -1, b = -1;
    int ans = 1000000;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            a = i;
            if (b != -1)
            {
                int diff = abs(a - b);
                ans = min(ans, diff);
            }
        }
        else if (arr[i] == y)
        {
            b = i;
            if (a != -1)
            {
                int diff = abs(a - b);
                ans = min(ans, diff);
            }
        }
    }
    if (ans == 1000000)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1, y = 2;
    cout << "The minimum distance is: " << minDist(arr, n, x, y);
    return 0;
}