#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_Possible(vector<int> vec, int n, int m, int mid)
{
    int studentCount = 1;
    int pagesum = 0;

    for (int i = 0; i <= n; i++)
    {
        if (pagesum + vec[i] <= mid)
        {
            pagesum += vec[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || vec[i] > mid)
            {
                return false;
            }
            pagesum = vec[i];
        }
    }
    return true;
}

int allocate_Book(vector<int> vec, int n, int m)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += vec[i];
    }

    int e = sum;
    int ans = -1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (is_Possible(vec, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
int main()
{
    vector<int> vec{10, 20, 30, 40, 50, 60};
    int n = vec.size() - 1;
    int m = 3;
    cout << "The allocation is: " << allocate_Book(vec, n, m);
    return 0;
}