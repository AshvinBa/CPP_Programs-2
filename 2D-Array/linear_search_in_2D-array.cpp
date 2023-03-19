#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPreasent(vector<vector<int>> vec1, int x)
{
    int n = vec1.size();
    int m = vec1[0].size();
    cout << n << endl
         << m << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vec1[row][col] == x)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m;
    cout << "Enter the limits: ";
    cin >> n >> m;
    vector<vector<int>> vec1(n, vector<int>(m));
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec1[i][j];
        }
    }
    cout << "\nThe matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    int x;
    cout << "Enter the digit for search: ";
    cin >> x;
    int k = isPreasent(vec1, x);
    if (k)
    {
        cout << "Yes!preasent.";
    }
    else
    {
        cout << "Not!preasent.";
    }
    return 0;
}