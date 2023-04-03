#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getPivote(vector<int> &arr, int k)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
            return mid;

        if (arr[mid] >= arr[start])
        {
            if (arr[mid] >= k && arr[start] <= k)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= k && arr[end] >= k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the element for search: ";
    cin >> k;
    cout << "The index of that number is: ";
    cout << getPivote(arr, k);
    return 0;
}