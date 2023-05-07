/*
Majority Element
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.


Example 1:
Input:
N = 3
A[] = {1,2,3}
Output:
-1
Explanation:
Since, each element in
{1,2,3} appears only once so there
is no major


Example 2:
Input:
N = 5
A[] = {3,1,3,3,2}
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is
the majority element.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int check(int a[], int n)
{    
    int elem = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            elem = a[i];
        }
        if (elem == a[i])
            cnt++;
        else
            cnt--;
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (elem == a[i])
        {
            cnt++;
        }
    }
    if (cnt > n / 2)
    {
        return elem;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 1, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = check(arr, n);
    cout << "The majority Element is: ";
    cout << res;
    return 0;
}

/*
App-2

unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second>n/2)
        return it.first;
    }
    return -1;

*/