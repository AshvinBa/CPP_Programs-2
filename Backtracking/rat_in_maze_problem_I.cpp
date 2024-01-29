/*
Rat in a Maze Problem - I

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && vis[x][y] != 1 && arr[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
               vector<vector<bool>> &vis, string path)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // 4 movment
        vis[x][y] = 1;

        // Down
        if (isSafe(x + 1, y, vis, arr, n))
        {
            solve(x + 1, y, arr, n, ans, vis, path + 'D');
        }
        // Left
        if (isSafe(x, y - 1, vis, arr, n))
        {
            solve(x, y - 1, arr, n, ans, vis, path + 'L');
        }
        // Right
        if (isSafe(x, y + 1, vis, arr, n))
        {
            solve(x, y + 1, arr, n, ans, vis, path + 'R');
        }
        // Right
        if (isSafe(x - 1, y, vis, arr, n))
        {
            solve(x - 1, y, arr, n, ans, vis, path + 'U');
        }
        vis[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &a, int n)
    {
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        string path = "";
        if (a[0][0] == 0)
        {
            ans.push_back("-1");
            return ans;
        }

        solve(0, 0, a, n, ans, visited, path);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
