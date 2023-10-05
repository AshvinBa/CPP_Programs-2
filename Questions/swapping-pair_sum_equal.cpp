/*
Swapping pairs make sum equal

Given two arrays of integers A[] and B[] of size N and M, the task is to check 
if a pair of values (one value from each array) exists such that swapping the 
elements of the pair will make the sum of two arrays equal.

Example 1:
Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in A[] = 11
Sum of elements in B[] = 15, To get same
sum from both arrays, we can swap following
values: 1 from A[] and 3 from B[]

Example 2:
Input: N = 4, M = 4
A[] = {5, 7, 4, 6}
B[] = {1, 2, 3, 8}
Output: 1
Explanation: We can swap 6 from array
A[] and 2 from array B[]
Your Task:
This is a function problem. You don't need to take any input, as it is already 
accomplished by the driver code. You just need to complete the function findSwapValues() 
that takes array A, array B, integer N, and integer M as parameters and returns 1 
if there exists any such pair otherwise returns -1.

Expected Time Complexity: O(MlogM+NlogN).
Expected Auxiliary Space: O(1).
*/

#include <iostream>
using namespace std;

int findSwapValues(int A[], int n, int B[], int m)
{
    unordered_map<int, int> mp;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
        a += A[i];

    for (int j = 0; j < m; j++)
        b += B[j], mp[B[j]] = 1;

    for (int i = 0; i < n; i++)
    {
        int bi = (b - a) / 2 + A[i];
        if ((b - a + 2 * A[i]) % 2 == 0 && mp.find(bi) != mp.end())
            return 1;
    }
    return -1;
}
int main()
{
    int N = 6, M = 4;
    int A[] = {4, 1, 2, 1, 1, 2};
    int B[] = {3, 6, 3, 3};
    cout << "The Number of swap required is: " << findSwapValues(A, N, B, M);
    return 0;
}