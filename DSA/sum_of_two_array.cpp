#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    while (s <= e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int> &v1, int n, vector<int> &v2, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;

    int carry = 0;

    while (i >= 0 && j >= 0)
    {
        int val1 = v1[i];
        int val2 = v2[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int val1 = v1[i];
        int sum = val1 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int val2 = v2[i];
        int sum = val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return reverse(ans);
}
int main()
{
    int n, m;
    cout << "Enter the limit of first and second array: ";
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    cout << "Enter the values for v1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    cout << "Enter the values for v2: ";
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    cout << "\nThe values for v1: ";
    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\nThe values for v2: ";
    for (int i = 0; i < m; i++)
    {
        cout << v2[i] << " ";
    }
    vector<int> result;
    result = findArraySum(v1, n, v2, m);
    cout << "\nANSWER: ";
    for (auto i = result.begin(); i != result.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
