/*
Maximum of all subarrays of size k
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

Example 2:
Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, 
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13}, 
Max = 90
Your Task:  
You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 107
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        // Remove elements that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        // Add the current element index to the deque
        dq.push_back(i);
        // If the current index is equal to or greater than k-1, add the maximum element to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}



// failed approach test case no. 17
/*
vector<int>ans;
        
        int n1=sizeof(arr)/sizeof(arr[0]);
        
        int i=1,j=k;
        int maxi=0;
        
        if(k==1 and n1==1)
        {
        return {arr[0]};
        }
        
        
        while(j<=n)
        {
            int d=i;
            while(d<j)
            {
                if(maxi<arr[d])
                {
                    maxi=arr[d];
                }
                d++;
            }
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
*/

// failed approach testcase no 126

/*

        vector<int>ans;
        int i=0;
        int j=k,d=i;
        int maxi=0;
        while(j<=n)
        {
            
        while(d<j)
        {
            maxi=max(maxi,arr[d]);
            d++;
        }
        ans.push_back(maxi);
        i++;
        j++;
        }
        return ans;

*/

//{ Driver Code Starts.













