/*
Leaders in an array
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 

 
Example 1:
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.
 

Example 2:
Input:
n = 5
A[] = {1,2,3,4,0}
Output: 4 0
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> leaders(int a[], int n)
{
    int max = a[n - 1];
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (max <= a[i])
        {
            s.push(a[i]);
            max = a[i];
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        int num = s.top();
        s.pop();
        ans.push_back(num);
        // s.pop();
    }
    return ans;
}

int main()
{
    long long n;
    cout << "Enter the size: ";
    cin >> n; // total size of array

    int a[n];

    // inserting elements in the array
    cout << "Enter the element: ";
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // calling leaders() function
    vector<int> v = leaders(a, n);

    // printing elements of the vector
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}
