/*
Left Rotate Matrix K times
You are given an integer k and matrix mat. Rotate the elements of the given matrix to the left k times and return the resulting matrix.

Examples:

Input: k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
2 3 1
5 6 4
8 9 7
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>  5 6 4
7 8 9       8 9 7

Input: k=2, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
3 1 2
6 4 5
9 7 8
Explanation: After rotating the matrix looks like
1 2 3       2 3 1       3 1 2
4 5 6  =>  5 6 4  =>   6 4 5
7 8 9       8 9 7       9 7 8

Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(n*m)

Constraints:
1<= mat.size, mat[0].size, mat[i][j] <=1000
1<=k<=10000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        
        for(auto &row : mat)
        {
            reverse(row.begin(),row.end());
            reverse(row.rbegin(),row.rbegin()+k);
            reverse(row.rbegin()+k,row.rend());
        }
        return mat;
    }
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        cout<<"Enter the value of n,m,k: ";
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        cout<<"The Rotated Matrix: ";
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
