/*
Maximum Consecutive Ones

You are given array nums of n length and an integer k .return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example:

Input:
n = 11
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
Output:
6
Explanation:
You can flip 2 0 and obtain  [1,1,1,0,0,1,1,1,1,1,1]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int n, int k)
{
    int i = 0;
    int j = 0;
    int maxlen = 0;
    int zerocount = 0;
    for (j = 0; j < n; j++)
    {
        if (nums[j] == 0)
            zerocount++;

        while (zerocount > k)
        {
            if (nums[i] == 0)
                zerocount--;

            i++;
        }
        maxlen = max(maxlen, j - i + 1);
    }
    return maxlen;
}

int main()
{
    vector<int> arr{1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1};
    int n = arr.size();
    int k = 3;
    cout << "\nAnswer: " << Longest_ones(arr, n, k);
    return 0;
}