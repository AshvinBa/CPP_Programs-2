#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int sum(vector<vector<int>> vec1)
{
    int s = 0;
    int n = vec1.size();
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < n; j++)
        {
            s += vec1[i][j];
        }
        cout << s << "\t";
    }
}
int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    vector<vector<int>> vec1(n, vector<int>(n));
    cout << "Enter the valueS: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
        }
    }
    cout << "The values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    sum(vec1);
    return 0;
}