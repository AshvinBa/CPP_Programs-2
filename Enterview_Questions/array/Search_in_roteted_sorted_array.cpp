#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &vec, int k, int st, int ed) /* Binary search for element searching*/
{
    int s = st;
    int e = ed;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (vec[mid] == k)
        {
            return mid;
        }
        else if (vec[mid] > k)
        {
            e = mid - 1;
        }
        else if (vec[mid] < k)
        {
            s = mid + 1;
        }
    }
    return -1;
}

int find_pivote(vector<int> &vec, int n) /*Find pivote number for position of rotation*/
{
    int s = 0;
    int e = n;
    int mid = (s + e) / 2;
    int ans = -1;

    while (s < e)
    {
        if (vec[mid] > vec[0])
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

int find_position(vector<int> &vec, int n, int k)
{
    int pivote;
    pivote = find_pivote(vec, n);
    if (k >= vec[pivote] && k <= vec[pivote]) /* condition for pivote element*/
    {
        return binary_search(vec, k, 0, pivote);
    }
    else
    {
        return binary_search(vec, k, pivote + 1, n - 1);
    }
}

int main()
{
    vector<int> vec{7, 8, 1, 3, 5};
    int n = vec.size();
    int k;
    cout << "Enter the number for search: " << endl;
    cin >> k;
    cout << "The Position is: ";
    cout << find_position(vec, n, k);
    return 0;
}