#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<vector<int>> vec, int r1, int r2, int c1, int c2)
{
    int sum = 0;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            sum += vec[i][j];
        }
    }
    return sum;
}
int main()
{
    int n;
    cout << "Enter the limits: ";
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }
    cout << "\nMatrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    int r1, r2, c1, c2;
    cout << "\nEnter the row R1 and R2 = ";
    cin >> r1 >> r2;
    cout << "\nEnter the coloum c1 and c2 = ";
    cin >> c1 >> c2;
    int sum = func(vec, r1, r2, c1, c2);
    cout << "SUM: " << sum;
    return 0;
}