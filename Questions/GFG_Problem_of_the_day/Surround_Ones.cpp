/*
Surround the 1's
Given a matrix of order nxm, composed of only 0's and 1's, find the number of 1's in the matrix that are surrounded by an even number (>0) of 0's. The surrounding of a cell in the matrix is defined as the elements above, below, on left, on right as well as the 4 diagonal elements around the cell of the matrix. Hence, the surrounding of any matrix elements is composed of 8 elements. Find the number of such 1's.

Example 1:
Input: 
matrix = {{1, 0, 0}, 
          {1, 1, 0}, 
          {0, 1, 0}}
Output: 
1
Explanation: 
1 that occurs in the 1st row and 1st column, has 3 surrounding elements 0,1 and 1. The occurrence of zero is odd. 
1 that occurs in 2nd row and 1st column has 5 surrounding elements 1,0,1,1 and 0. The occurrence of zero is even. 
1 that occurs in 2nd row and 2nd column has 8 surrounding elements. The occurrence of 0 is odd. 
Similarly, for the 1 that occurs in 3rd row and 2nd column, the occurrence of zero in it's 5 surrounding elements is odd. 
Hence, the output is 1.

Example 2:
Input: 
matrix = {{1}}
Output: 
0
Explanation: 
There is only 1 element in the matrix. Hence, it has no surroundings, so it's count for even 0's is 0 for the whole matrix. 
0 is even but we want occurrence of a zero in the surrounding at least once. 
Hence, output is 0.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count_Zeros(vector<vector<int>> &mat, int i, int j, int n, int m)
{
    int c = 0;

    if (i - 1 >= 0 && mat[i - 1][j] == 0)
        c++;
    if (i + 1 < n && mat[i + 1][j] == 0)
        c++;
    if (j - 1 >= 0 && mat[i][j - 1] == 0)
        c++;
    if (j + 1 < m && mat[i][j + 1] == 0)
        c++;
    if (i - 1 >= 0 && j - 1 >= 0 && mat[i - 1][j - 1] == 0)
        c++;
    if (i - 1 >= 0 && j + 1 < m && mat[i - 1][j + 1] == 0)
        c++;
    if (i + 1 < n && j + 1 < m && mat[i + 1][j + 1] == 0)
        c++;
    if (i + 1 < n && j - 1 >= 0 && mat[i + 1][j - 1] == 0)
        c++;

    return c;
}

int Count(vector<vector<int>> &matrix)
{
    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                int cnt = count_Zeros(matrix, i, j, n, m);
                if (cnt != 0 && cnt % 2 == 0)
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the values in Array: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "The matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    if (Count(matrix))
    {
        cout << "Yes.";
    }
    else
    {
        cout << "No.";
    }
    return 0;
}kl;