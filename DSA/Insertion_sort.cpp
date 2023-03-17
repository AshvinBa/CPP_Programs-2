#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertion_Sort(vector<int> &vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = vec[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (vec[j] > temp)
            {
                vec[j + 1] = vec[i];
            }
            else
            {
                break;
            }
        }
        vec[j + 1] = temp;
    }
}
int main()
{
    vector<int> vec{11, 2, 13, 5, 6};
    int n = vec.size();
    insertion_Sort(vec, n);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}