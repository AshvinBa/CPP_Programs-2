/*
Count number of hops
A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

Example 1:
Input:
N = 1
Output: 1

Example 2:
Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 ≤ N ≤ 105
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
    long long countWays(int n,vector<int>&dp)
    {
        if(n==0 || n==1)
        return 1;
        if(n==2)return 2;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int ways1=countWays(n-1,dp);
        int ways2=countWays(n-2,dp);
        int ways3=countWays(n-3,dp);
        
        return dp[n]=((ways1%mod+ways2%mod)%mod+ways3%mod)%mod;
    }
    
    long long countWays(int n)
    {
        vector<int>dp(n+1,-1);
        long long ans=countWays(n,dp);
        return ans;   
    }

int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    cout<<"Answer: "<<countWays(n);
return 0;
}