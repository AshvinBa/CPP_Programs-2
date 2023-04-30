#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int powerfullInteger(int n, vector<vector<int>> &intervals, int k)
{
    map<int, int> mp;
    for (auto it : intervals)
    {
        int l = it[0], r = it[1];
        mp[l]++;
        mp[r + 1]--;
    }
    int curr = 0;
    int maxi = -1;
    bool flag = false;
    for (auto it : mp)
    {
        curr += it.second;
        if (curr >= k)
        {
            flag = true;
            maxi = it.first;
        }
        else if (flag == true)
        {
            maxi = it.first - 1;
            flag = false;
        }
        else
        {
            flag = false;
        }
    }
    return maxi;
}

int main()
{
    vector<vector<int>> arr{{1, 3}, {4, 6}, {3, 4}};
    int n = arr.size();
    int k = 2;
    cout<<"Answer: "<<powerfullInteger(n,arr,k);
    return 0;
}