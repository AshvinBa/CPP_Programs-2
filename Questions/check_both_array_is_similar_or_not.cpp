#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &A, vector<int> &B, int n)
{
    unordered_map<int, int> m1;

    for (int i = 0; i < n; i++)
    {
        m1[A[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int key = B[i];
        if (m1.find(key) != m1.end()) // found.
        {
            auto itr = m1.find(key);

            if (itr->second > 0)
                itr->second--;
            else
                return false;
        }
        else
            return false;
    }
    return true;
}
int main()
{
    int n;

    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{1, 2, 8, 4, 5};
    n = v1.size();

    int x = check(v1, v2, n);
    if (x)
    {
        cout << "YES Equal.";
    }
    else
    {
        cout << "Not Equal.";
    }
    return 0;
}