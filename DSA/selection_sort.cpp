#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int selection_Sort(vector<int> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[index] > vec[j])
                index = j;
        }
        swap(vec[i], vec[index]);
    }
}

int main()
{
    vector<int> vec{100, 25, 20, 012, 25, 190};
    int n = vec.size();
    selection_Sort(vec, n);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}