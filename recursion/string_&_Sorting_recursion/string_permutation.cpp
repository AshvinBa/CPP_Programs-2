#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans1, vector<int> num, int index)
{
    if (index >= num.size())
    {
        ans1.push_back(num);
        return;
    }

    for (int j = index; j < num.size(); j++)
    {
        swap(num[index], num[j]);
        solve(ans1, num, index + 1);
        swap(num[index], num[j]);
    }
}

vector<vector<int>> perm(vector<int> &num)
{
    vector<vector<int>> ans1;
    int index = 0;
    solve(ans1, num, index);
    return ans1;
}
int main()
{
    vector<int> num{1, 2, 3};
    vector<vector<int>> str = perm(num);
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str[0].size(); j++)
        {
            cout << str[i][j] << "";
        }
        cout << " ";
    }
    return 0;
}