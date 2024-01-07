/*
Smallest range in K lists

Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:
Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Example 2:
Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

Constraints:
1 <= K,N <= 500
0 <= a[ i ] <= 105

*/

#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int K)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>q;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int range = INT_MAX;
        int low = 0, high = 0;

        for (int i = 0; i < K; i++)
        {
            q.push({arr[i][0], {i, 0}});
            mini = min(arr[i][0], mini);
            maxi = max(arr[i][0], maxi);
        }

        while (true)
        {
            pair<int, pair<int, int>> temp = q.top();
            q.pop();

            int mini1 = temp.first;

            if (range > maxi - mini1)
            {
                mini = mini1;
                low = mini;
                high = maxi;
                range = maxi - mini;
            }

            int i = temp.second.first;
            int j = temp.second.second;

            if (j == n - 1)
                break;

            q.push({arr[i][j + 1], {i, j + 1}});

            if (maxi < arr[i][j + 1])
            {
                maxi = arr[i][j + 1];
            }
        }
        return {low, high};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
