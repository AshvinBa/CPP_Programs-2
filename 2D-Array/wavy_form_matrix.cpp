#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> wavyOrder(vector<vector<int>> &vec1, int row, int col)
{
    vector<int> ans;
    for (int j = 0; j < row; j++)
    {
        if (j % 2 == 1)
        {
            for (int i = row - 1; i >= 0; i--)
            {
                ans.push_back(vec1[i][j]);
            }
        }
        else
        {
            for (int i = 0; i < row; i++)
            {
                ans.push_back(vec1[i][j]);
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the row and coloumn: ";
    cin >> n;
    vector<vector<int>> vec1(n, vector<int>(n));
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
        }
    }
    vector<int> res = wavyOrder(vec1, n, n);
    cout << "The array is:\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}