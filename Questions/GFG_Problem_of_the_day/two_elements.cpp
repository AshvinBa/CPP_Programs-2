/*
Two Repeated Elements

You are given an array of N+2 integer elements. All elements of the array are in the range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X repeats twice before Y repeating twice, then the order should be (X, Y).

Example 1:
Input:
N = 4
array[] = {1,2,1,3,4,3}
Output: 1 3
Explanation: In the given array,
1 and 3 are repeated two times.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> check(vector<int> arr, int n)
{
    vector<int> ans;
    for (auto n : arr)
    {
        n = abs(n);
        if (arr[n - 1] > 0)
            arr[n - 1] *= -1;
        else
            ans.push_back(n);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 3};
    int N = 5;
    vector<int> res = check(arr, N);
    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}

/*

vector<int> twoRepeated (int arr[], int N) {
    vector<int>ans;
    for(auto n:arr)
    {
    n=abs(n);
    if(arr[n-1]>0)
    arr[n-1]*=-1;
    else
    ans.push_back(n);
    }
    return ans;
    }

*/