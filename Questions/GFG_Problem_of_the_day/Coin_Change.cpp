/*
Coin Change

Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

Example 1:
Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.

Example 2:
Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int count(int coins[], int n, int sum)
{

    vector<vector<long long>> dp(n, vector<long long>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            long long take, notake;
            take = notake = 0;

            if (j >= coins[i])
                take = dp[i][j - coins[i]];

            if (i > 0)
                notake = dp[i - 1][j];

            dp[i][j] = take + notake;
        }
    }
    return dp[n - 1][sum];
}

int main()
{
    int n;
    cout << "Enter the limit of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cout << "Enter the sum: ";
    cin >> sum;
    cout << "\nAnswer: " <<count(arr,  n, sum)<< endl;
    return 0;
}