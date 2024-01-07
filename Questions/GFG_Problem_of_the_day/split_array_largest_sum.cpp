/*
Split Array Largest Sum

Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Example 1:
Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits. 

Example 2:
Input:
N = 3, K = 2
A[] = {1, 1, 2}
Output:
2
Explanation:
Splitting the array as {1,1} and {2} is optimal.
This results in a maximum sum subarray of 2.
Your Task:
You do not have to take any input or print anything. The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays such that maximum sum subarray is minimum possible.

Expected Time Complexity: O(N*log(sum(arr))).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
1 ≤ arr[i] ≤ 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  bool isPossible(int arr[],int N,int mid,int K)
    {
        int count=1;
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            
            if(sum>mid)
            {
                count++;
                sum=arr[i];
            }
        }
        return K>=count;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        int low=INT_MIN;
        int high=0,mid,ans=INT_MAX;
        
        for(int i=0;i<N;i++)
        {
            low=max(arr[i],low);
            high+=arr[i];
        }
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            if(isPossible(arr,N,mid,K))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
      
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}