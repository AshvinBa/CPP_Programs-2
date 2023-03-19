#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> vec, int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i - 1] > vec[i])
            count++;
    }
    if (vec[n - 1] > vec[0])
        count++;

    return count <= 1;
}
int main()
{
    vector<int> vec{7, 8, 10, 11, 12, 15, 16, 1, 2, 3, 4, 5};
    int n = vec.size();
    int k = func(vec, n);
    if (k == 0)
    {
        cout << "Array is Not Roteted.";
    }
    else
    {
        cout << "Yes Array is Rotated.";
    }
    return 0;
}