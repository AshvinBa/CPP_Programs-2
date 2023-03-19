#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum(vector<vector<int>> vec1)
{
    int s = 0;
    int n = vec1.size();
    int max = INT16_MIN;
    int maxsum = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < n; j++)
        {
            s += vec1[i][j];
        }
        // cout << s << "\t";
        maxsum = s;
        if (maxsum > max)
        {
            max = maxsum;
            index = i;
        }
    }
    cout << "The sum is: " << max << " and index is: " << index + 1 << endl;
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
    cout << "The Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << vec1[i][j] << " ";
        }
        cout << endl;
    }
    sum(vec1);
    return 0;
}