/*

Spirally traversing a matrix

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {

        vector<int> ans;

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        int direction = 0;

        while (left <= right && top <= bottom)
        {
            if (direction == 0)
            {
                for (int col = left; col <= right; col++)
                {
                    ans.push_back(matrix[top][col]);
                }
                top++;
            }
            else if (direction == 1)
            {
                for (int row = top; row <= bottom; row++)
                {
                    ans.push_back(matrix[row][right]);
                }
                right--;
            }
            else if (direction == 2)
            {
                for (int col = right; col >= left; col--)
                {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            else if (direction == 3)
            {
                for (int row = bottom; row >= top; row--)
                {
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }

            direction = (direction + 1) % 4;
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
        int r, c;
        cout<<"Enter the number of row and column: ";
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        cout<<"Enter the values: ";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        cout<<"Spiral Path: ";
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}