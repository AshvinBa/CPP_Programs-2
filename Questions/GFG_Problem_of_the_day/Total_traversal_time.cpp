/*
Total Traversal Time

Given two arrays arr[ ] and peanlty[ ], each of size n.
All elements in arr[ ] are in the range of 1 to n. You have to traverse arr[ ] from start to end while following the given conditions.

If element has never occured before, it takes 1 second to move a step ahead.
If element has occured before, it will take penalty[arr[i]] seconds to move a step. Here i is the index of current element with 1 based indexing.
Find the total time taken to traverse through the array.

Example 1:

Input:
n = 4
arr[ ] = {1, 2, 3, 3}
penalty[ ] = {1, 2, 3, 4}
Output: 5
Explanation:


For i = 1, traversal time = 0 second since this is the start point.  
For i = 2, traversal time = 1 second 
For i = 3, traversal time = 1 second 
For i = 4, traversal time = penalty[arr[4]]  = penalty[3] = 3
Total = 0+1+1+3 = 5 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int totalTime(int n, vector<int> &arr, vector<int> &penalty) {
        // code here
        int res=0;
        unordered_set<int>set;
        set.insert(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(set.find(arr[i])!=set.end())
            {
                res+=penalty[arr[i]-1];
            }
            else
            {
                res++;
            }
            set.insert(arr[i]);
        }
        return res;
    }

int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    vector<int> arr(n), penalty(n);
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the Panelty: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> penalty[i];
    }
    cout << "Answer: ";
    cout << totalTime(n, arr, penalty);
    return 0;
}