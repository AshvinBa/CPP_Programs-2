/*
Strictly Increasing Array

Given an array nums of n positive integers. Find the minimum number of operations required to modify the array such that array elements are in strictly increasing order (nums[i] < nums[i+1]).
Changing a number to greater or lesser than original number is counted as one operation.

Note: Array elements can become negative after applying operation.
Example 1:
Input:
n = 6
nums = [1, 2, 3, 6, 5, 4]
Output: 
2
Explanation: 
By decreasing 6 by 2 and increasing 4 by 2, nums will be like [1, 2, 3, 4, 5, 6] which is stricly increasing.

Example 2:
Input: 
n = 4
nums = [1, 1, 1, 1]
Output: 
3
Explanation: 
One such array after operation can be [-2, -1, 0, 1]. We require atleast 3 operations for this example.
Your Task:
You don't need to read or print anything. Your task is to complete the function min_opeartions() which takes the array nums as input parameter and returns the minimum number of opeartion needed to make the array strictly increasing.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)

Constraints: 
1 <= n <= 103
1 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int min_operations(vector<int>& nums) 
    {
    int n = nums.size() , temp=1;
    vector<int> dp(n, 1); // dp[i] represents the minimum operations required to make nums[i] strictly increasing

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] - nums[j] >= i-j) {
                dp[i] = max(dp[i], dp[j] + 1);
                temp = max(dp[i],temp);
            }
        }
    }
    return n-temp;
    }
};

int main() {
        int n;
        cout<<"Enter the size: ";
        cin >> n;
        vector<int> nums(n);
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    return 0;
}