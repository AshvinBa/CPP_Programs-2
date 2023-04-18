// Key Pair

// Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

// Example 1:

// Input:
// N = 6, X = 16
// Arr[] = {1, 4, 45, 6, 10, 8}
// Output: Yes
// Explanation: Arr[3] + Arr[4] = 6 + 10 = 16

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    unordered_map<int, int> m1;
    int ans = x;
    for (int i = 0; i < n; i++)
    {
        m1[arr[i]]++;
    }
    for (auto itr = m1.begin(); itr != m1.end(); itr++)
    {
        int key = itr->first;
        int val = itr->second;

        int pair = ans - key;
        if (pair == key)
        {
            if (val > 1)
                return true;
        }
        else
        {
            if (m1.find(pair) != m1.end())
                return true;
        }
    }
    return false;
}

int main()
{
    int n = 6;
    int x = 6;
    int arr[] = {1, 4, 45, 6, 10, 8};
    int x1 = hasArrayTwoCandidates(arr, n, x);
    cout << "\nAnswer: " << x1;
    return 0;
}
