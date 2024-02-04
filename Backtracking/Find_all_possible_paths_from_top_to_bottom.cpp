/*
Find all possible paths from top to bottom

Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

Example 1:
Input: 1 2 3
       4 5 6
Output: 1 4 5 6
        1 2 5 6
        1 2 3 6
Explanation: We can see that there are 3
paths from the cell (0,0) to (1,2).

Example 2:
Input: 1 2
       3 4
Output: 1 2 4
        1 3 4
Your Task:
You don't need to read input or print anything. Your task is to complete the function findAllPossiblePaths() which takes two integers n,m and grid[][]  as input parameters and returns all possible paths from the top left cell to bottom right cell in a 2d array.

Expected Time Complexity: O(2^N*M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= n,m <= 10
1 <= grid[i][j] <= n*m
n * m < 20
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int> path)
    {
        if (i == n - 1 && j == m - 1)
        {
            path.push_back(grid[i][j]);
            ans.push_back(path);
            return;
        }
        else if (i == n - 1)
        {
            path.push_back(grid[i][j]);
            solve(i, j + 1, n, m, grid, path);
        }
        else if (j == m - 1)
        {
            path.push_back(grid[i][j]);
            solve(i + 1, j, n, m, grid, path);
        }
        else
        {
            path.push_back(grid[i][j]);
            // down
            solve(i + 1, j, n, m, grid, path);
            // right
            solve(i, j + 1, n, m, grid, path);
        }
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> path;
        solve(0, 0, n, m, grid, path);
        return ans;
    }
};


int main()
{
    cout << "Enter the row and column: ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution ob;
    cout << "Number of path available: ";
    auto ans = ob.findAllPossiblePaths(n, m, grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}


/*
Failed approach.

    bool isSafe(vector<vector<int>>&grid,int n,int m,int row,int col,vector<vector<bool>>&vis)
    {
        if((row<n && row>=0) && (col<m && col>=0) && vis[row][col]!=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(int row,int col,vector<vector<int>>&grid,vector<vector<bool>>&vis,
    int n,int m,vector<vector<int>>&ans)
    {
        // vector<int>path;
        if(row==n-1 && col==m-1)
        {
            // ans.push_back(path);
            return;
        }

        vis[row][col]=1;

        if(isSafe(grid,n,m,row,col+1,vis))
        {
            ans.push_back(grid[row][col+1]);
            solve(row,col+1,grid,vis,n,m,ans);
        }
        if(isSafe(grid,n,m,row+1,col,vis))
        {
            ans.push_back(grid[row+1][col]);
            solve(row+1,col,grid,vis,n,m,ans);
        }

        vis[row][col]=0;
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<bool>>vis;
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,0,grid,vis,n,m,ans);
        return ans;
    }
};
*/