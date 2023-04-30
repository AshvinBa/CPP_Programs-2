/*
Binary matrix having maximum number of 1s

Given a binary matrix (containing only 0 and 1) of order NxN. All rows are sorted already, We need to find the row number with the maximum number of 1s. Also, find the number of 1s in that row.
Note:

1. In case of a tie, print the smaller row number.
2. Row number should start from 0th index.

Example 1

Input:
N=3
mat[3][3] = {0, 0, 1,
              0, 1, 1,
              0, 0, 0}
Output:
Row number = 1
MaxCount = 2
Explanation:
Here, max number of 1s is in row number 1
and its count is 2.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxRow(vector<vector<int>> mat, int N)
{
    int maxCnt = 0, maxRow = -1;
    for (int i = 0; i < N; i++)
    {
        int zeros = upper_bound(mat[i].begin(), mat[i].end(), 0) - mat[i].begin();
        int ones = N - zeros;
        if (maxCnt < ones)
        {
            maxCnt = ones;
            maxRow = i;
        }
    }
    return {maxRow, maxCnt};
}
int main()
{
    vector<vector<int>> mat{{0, 0, 1}, {0, 1, 1}, {0, 0, 0}};
    int n = mat.size();
    vector<int> vec = findMaxRow(mat, n);
    cout<<"Row Number: ";
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
