/*
Painting the Fence

Given a fence with n posts and k colors, find out the number of ways of painting 
the fence so that not more than two consecutive posts have the same colors. Since 
the answer can be large return it modulo 109 + 7.

Example 1:
Input:
n = 3
k = 2 
Output: 6
Explanation: 
Let the 2 colours be 'R' and 'B'.
We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR

Example 2:
Input:
n = 2
k = 4 
Output: 16
Explanation: 
After coloring first post with 4 possible combinations, 
you can still color next posts with all 4 colors. Total 
possible combinations will be 4x4=16
Your Task:
Since, this is a function problem. You don't need to take any 
input or print anything, as it is already accomplished by the 
driver code. You just need to complete the function countWays() 
that takes n and k as parameters and returns the number of ways 
in which the fence can be painted (modulo 109 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ 105

*/

#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

class Solution{
    public:
    long long mod=1000000007;
    
    int add(int a, int b)
    {
        return (a%mod + b%mod)%mod;
    }
    int mul(int a, int b)
    {
        return ((a%mod)*1LL*(b%mod))%mod;
    }
    
    long long solveTab(int n,int k)
    {
        vector<int>dp(n+1,0);
        dp[1]=k;
        dp[2]=add(k,mul(k,k-1));
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=add(mul(dp[i-2],k-1), mul(dp[i-1],k-1));
        }
        return dp[n];
    }
    
    long long countWays(int n, int k){
        return solveTab(n,k);
    }
};

int main()
{
	
	int t;
    cout<<"Number of test cases: ";
	cin>>t;
	while(t--)
	{
        cout<<"Enter the values of n and k: ";
		int n,k;
		cin>>n>>k;
		Solution ob;
        cout<<"Answer: ";
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}