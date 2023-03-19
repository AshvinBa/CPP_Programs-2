#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool binary_search(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    int target;
    cout << "Enter the target: ";
    cin >> target;

    int s = 0;
    int e = row * col - 1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        int ele = mat[mid / col][mid % col];

        if (ele == target)
        {
            return 1;
        }

        if (ele < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return 0;
}
int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    bool x = binary_search(mat);
    if (x == 1)
    {
        cout << "Yes!";
    }
    else
    {
        cout << "No";
    }
    return 0;
}