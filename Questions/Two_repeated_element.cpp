/*
Two Repeated Elements
You are given an array of N+2 integer elements. All elements of the array are in the range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X repeats twice before Y repeating twice, then the order should be (X, Y).

Example 1:
Input:
N = 4
array[] = {1,2,1,3,4,3}
Output: 1 3
Explanation: In the given array,
1 and 3 are repeated two times.

Example 2:
Input:
N = 2
array[] = {1,2,2,1}
Output: 2 1
Explanation: In the given array,
1 and 2 are repeated two times
and second occurence of 2 comes
before 1. So the output is 2 1.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoRepeated(int arr[], int N)
{
    vector<int> ans;

    unordered_map<int, int> mp;

    for (int i = 0; i < N + 2; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == 2)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int arr[n];
    cout << "Entre the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = twoRepeated(arr, n);
    cout << "Answer: ";
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}