/*
Padovan Sequence

Given a number n, find the nth number in the Padovan Sequence.

A Padovan Sequence is a sequence which is represented by the following recurrence relation
P(n) = P(n-2) + P(n-3)
P(0) = P(1) = P(2) = 1

Note: Since the output may be too large, compute the answer modulo 10^9+7.

Examples :

Input: n = 3
Output: 2
Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1

Input: n = 4
Output: 2
Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution { 
  public:
  
    int padovanSequence(int n) {
        
        int dp[n+1];
        int mod=1e9+7;
        
        dp[0]=1;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-2]+dp[i-3])%mod;
        }
        return dp[n]%mod;
    }
};


int main() {
    int t;
    cout<<"Entre the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Enter the value of N: ";
        cin >> n;
        Solution ob;
        cout<<"Answer: ";
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}