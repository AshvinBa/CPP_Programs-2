/*
POTD
Tree Transformation

You are given a tree containing N nodes in the form of an array P where Pi represents the parent of the i-th node and P0 = -1 as the tree is rooted at node 0. In one move, you can merge any two adjacent nodes. Calculate the minimum number of moves required to turn the tree into a star tree.

-> Merging adjacent nodes means deleting the edge between them and considering both the nodes as a single one.
-> A Star tree is a tree with a center node, and all other nodes are connected to the center node only.

Example 1:
Input:
N = 5
p[] = {-1, 0, 0, 1, 1}
Output:
1
Explanation:
Tree looks like:

Merge the edge 0 - 2 in one operation
Our Tree will look like:

Example 2:
Input: N = 8
p[] = {-1 0 0 0 0 2 2 5}
Output:
2
Explanation:
Tree looks like:
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(vector<int> arr, int n)
{
    vector<int> temp(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        temp[arr[i]]++;
        temp[i]++;
    }
    int ans = n - 1;

    for (auto x : temp)
    {
        if (x == 1)
        {
            ans--;
        }
    }
    if (ans < 0)
        return 0;

    return ans;
}

int main()
{
    vector<int> arr{-1, 0, 0, 1, 1};
    int n = arr.size();
    cout << "\nAnswer: " << solve(arr, n);
    return 0;
}
