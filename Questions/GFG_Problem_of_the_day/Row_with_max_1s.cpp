/*
Row with max 1s
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:
1)
Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).

2)
Input: arr[][] = [[0, 0],
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0, j = m - 1;
        int ans = -1;

        while (i < n && j >= 0)
        {
            if (arr[i][j] == 1)
            {
                ans = i;
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--)
    {
        int n, m;
        cout<<"Enter the number of rows and columns: ";
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout<<"Answer: ";
        cout << ans << "\n";
    }
    return 0;
}
