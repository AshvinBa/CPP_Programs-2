/*
Find Nth root of M

You are given 2 numbers (n , m); the task is to find n√m (nth root of m).

Example 1:
Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9

Example 2:
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.


Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. If the root is not integer then returns -1.

Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 30
1 <= m <= 109
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int start = 1, end = m;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            double num = pow(mid, n);

            if (num == m)
                return mid;

            else if (num > m)
                end = mid - 1;

            else if (num < m)
                start = mid + 1;
        }
        return -1;
    }

    /*
    TLE at 100
    int NthRoot(int n, int m)
    {
        int ans=0;
        int cnt=0;
        if(m==1 and n>0)
        {
            return m;
        }
        else if(m>0 and n==1)
        {
            return m;
        }
        if(m%2==1)
        {
            for(int i=0;i<(m/2)+1;i++)
            {
                ans=0;
                ans=pow(i,n);
                if(ans==m)
                {
                    return i;
                }
            }
        }
        else
        {
            for(int i=0;i<(m/2)+1;i++)
            {
                ans=0;
                ans=pow(i,n);;
                if(ans==m)
                {
                    return i;
                }
            }
        }
        return -1;
    }
    */
};

int main()
{
    cout << "Enter the values of n and m: ";
    int n, m;
    cin >> n >> m;
    Solution ob;
    int ans = ob.NthRoot(n, m);
    cout << ans << "\n";

    return 0;
}