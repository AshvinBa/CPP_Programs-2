#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> func(vector<int> vec, int n, int k)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] + vec[j] == k)
            {
                ans.push_back(vec[i]);
                ans.push_back(vec[j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6};
    int n = vec.size();
    int k;
    cout << "Enter the key elements: ";
    cin >> k;
    vector<int> ans = func(vec, n, k);
    for (auto i = ans.begin(); i < ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}