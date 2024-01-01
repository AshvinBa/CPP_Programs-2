/*
Array Pair Sum Divisibility Problem

Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :
Input : 
nums = [9, 5, 7, 3]
k = 6
Output: 
True
Explanation: 
{(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:
Input : 
nums = [4, 4, 4]
k = 4
Output: 
False
Explanation: 
You can make 1 pair at max, leaving a single 4 unpaired.
Your Task:
You don't need to read or print anything. Your task is to complete the function canPair() which takes array nums and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

Expected Time Complexity: O(n)
Expected Space Complexity : O(n)

Constraints:
1 <= length( nums ) <= 105
1 <= numsi <= 105
1 <= k <= 105

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        
        int size=arr.size();
        
        if(size%2!=0)   /*The Number of digit in array is odd then pair is not possible for one digit.*/
        {
            return false;
        }
        
        vector<int> vec(k+1,0);
        for(auto i:arr)
        {
            i=i%k;
            vec[i]++; /*increase to 1.*/
            vec[k-i]--;  /* decrement for 0.*/
        }
        
        for(int i=1;i<k;i++)
        {
            if(vec[i]>0)
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int tc;
    cout<<"Enter the number of test cases: ";
    cin >> tc;
    while (tc--) {
        int n, k;
        cout<<"Enter the size and value of k: ";
        cin >> n >> k;
        vector<int> nums(n);
        cout<<"Enter the values: ";
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}