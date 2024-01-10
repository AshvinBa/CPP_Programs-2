/*
Longest subarray with sum divisible by K

Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:
Input:
N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 
4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.

Example 2:
Input:
N = 7, K = 3
arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output: 
5
Explanation:
The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
Your Task:
The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= K <= 109
-109 <= A[i] <= 109 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int cnt=0;
	    int sum=0,ans=0;
	    
	    unordered_map<int,int>mp;
	    
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        int remainders=sum%k;
	        
	        if(remainders<0)
	        remainders+=k;
	        
	        if(remainders==0)
	        {
	            ans=i+1;
	        }
	        else
	        {
	            if(mp[remainders])
	            ans=max(ans,i+1-mp[remainders]);
	            else
	            mp[remainders]=i+1;
	        }
	    }
	    return ans;
	}
};


int main()
{
	int t;
    cout<<"Enter the test cases: ";
	cin>>t;
	while(t--)
	{
	int n,k,i;
    cout<<"Enter the size and values of K: ";
	cin>>n>>k; int arr[n];
    cout<<"Enter the values: ";
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
