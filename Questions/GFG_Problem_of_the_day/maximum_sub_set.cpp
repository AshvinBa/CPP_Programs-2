/*
Maximum subset sum

Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive elements in the array, at least one of the elements is present in our subset.

Example 1:
Input:
N = 4
A[] = {1, -1, 3, 4}
Output: 8
Explanation:
We can choose 0th,2nd & 3rd index(0 based
Index),so that it can satisfy the
condition & can make maximum sum 8.

Example 2:
Input:
N = 3
A[] =  {0, 2, 0};
Output: 2
Explanation:
We can choose 1st index. Here the
maximum possible sum is 2.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long newt(int N, vector<int> &A, int index, int ind, vector<vector<long long>> &incr)
{
    if (index == N)
        return 0;

    if (incr[index][ind] != -1)
        return incr[index][ind];

    long long a = INT_MIN, b = INT_MIN;
    if (ind == 1)
    {
        b = newt(N, A, index + 1, 0, incr);
    }
    a = A[index] + newt(N, A, index + 1, 1, incr);

    return incr[index][ind] = max(a, b);
}

long long findMaxSubsetSum(int N, vector<int> &A)
{
    vector<vector<long long>> incr(N, vector<long long>(2, -1));
    return newt(N, A, 0, 1, incr);
}

int main()
{
    vector<int> arr{0, 2, 0};
    int n = arr.size();
    cout << "\nAnswer: " << findMaxSubsetSum(n, arr);
    return 0;
}
