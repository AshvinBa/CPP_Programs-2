/*
Zero Sum Subarrays
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

Example 1:
Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:
Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 
Expected Time Complexity: O(n*log(n))
Expected Auxilliary Space: O(n)
 
Constraints:    
1 <= n <= 10^6
-10^9 <= arr[ i ] <= 10^9
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n ) {
        
        unordered_map<long long int , int>mp;
        long long sum=0;
        long long ans=0;
        mp[0]=1;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!=mp.end())
            {
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
int main()
 {
        int n;
        cout<<"Enter the limit: ";
        cin>>n; 
       
        vector<long long int> arr(n,0);
        cout<<"Insert values: ";
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        cout << findSubarray(arr,n) << "\n";
    
	return 0;
}