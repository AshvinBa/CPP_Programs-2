#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> pascals(n);
    for (int i = 0; i < n; i++)
    {
        pascals[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || i == j)
            {
                pascals[i][j] = 1;
            }
            else
            {
                pascals[i][j] = pascals[i - 1][j] + pascals[i - 1][j - 1];
            }
        }
    }
    return pascals;
}
int main()
{
    int n;
    cout << "Enter the number for Pascals Triangle: ";
    cin >> n;
    vector<vector<int>> vec;
    vec = pascalTriangle(n);
    cout << "\nThe pascals Triangle is: \n";
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}