/*
find the minimum time require to paint the area in an array of contiguous section of board.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool partition(vector<int> &arr, int n, int mid, int m)
{
    int paintercount = 1;
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            paintercount++;
            if (paintercount > m || arr[i] > mid)
            {
                return false;
            }
            sum=0;
            sum += arr[i];
        }
    }
    return true;
}

int findDistance(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = -1;

    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (partition(arr, n, mid, m))
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
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the values: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    n = vec.size() - 1;
    int k = 2;
    cout << "The painters Time require is: " << findDistance(vec, n, k);
    return 0;
}