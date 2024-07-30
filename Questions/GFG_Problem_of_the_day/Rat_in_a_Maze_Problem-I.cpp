/*
Rat in a Maze Problem - I
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

1)
Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

2)
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool isSafe(int x, int y, vector<vector<bool>> &vis, 
    vector<vector<int>>&arr, int n)
    {
        if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]!=1 && arr[x][y]==1)
        return true;
        else 
        return false;
    }
  
    void solve( int x, int y, vector<vector<int>>&arr, int n, 
    vector<string>&ans, vector<vector<bool>>&vis, string path )
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        vis[x][y]=1;
        
        if(isSafe(x+1, y, vis, arr, n))
        {
            solve( x+1, y, arr, n, ans, vis, path+'D');
        }
        
        if(isSafe(x-1, y, vis, arr, n))
        {
            solve( x-1, y, arr, n, ans, vis, path+'U');
        }
        
        if(isSafe(x, y+1, vis, arr, n))
        {
            solve( x, y+1, arr, n, ans, vis, path+'R');
        }
        
        if(isSafe(x, y-1, vis, arr, n))
        {
            solve( x, y-1, arr, n, ans, vis, path+'L');
        }
        
        vis[x][y]=0;
        
    }
  
    vector<string> findPath(vector<vector<int>> &a) 
    {
        int n=a.size();
        vector<string>ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        string path="";
        
        if(a[0][0] == 0)
        {
            ans.push_back("-1");
            return ans;
        }
        
        solve(0,0,a,n,ans,visited,path);
        return ans;
    }
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Entre the size: ";
        cin >> n;
        cout<<"Enter the values: ";
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        cout<<"Answer: ";
        vector<string> result = obj.findPath(m);
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