/*
House Robber

You are a professional robber planning to rob houses along a street.Each house has a certain amount of money 
stashed, the only constraint  stopping you from robbing each of them is that adjacent houses have security
systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
 
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*
vector<int> dp(101, -1);
int fun(vector<int>& nums, int n) {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = max(fun(nums, n - 1), nums[n - 1] + fun(nums, n - 2));
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        fill(dp.begin(), dp.end(), -1);
        return fun(nums, n);
    }
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int n)
{
    int prev2=0;
    int prev1=arr[0];

    for(int i=1;i<n;i++)
    {
        int incl=prev2+arr[i];
        int excl=prev1+0;

        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int houseRobber(vector<int>&amount,int n)
{
    if(n==1)
    return amount[0];

    vector<int>first,second;

    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            first.push_back(amount[i]);
        }
        if(i!=0)
        {
            second.push_back(amount[i]);
        }
    }
    return max(solve(first,n-1),solve(second,n-1));
}

int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>amount(n);
    cout<<"Entre the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>amount[i];
    }
    cout<<"The Maximum stoolen amount is: ";
    cout<<houseRobber(amount,n);
    return 0;
}