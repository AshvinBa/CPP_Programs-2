/*
Find the Highest number

Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

Note: a[i] != a[i+1] 

Example 1:
Input:
11
1 2 3 4 5 6 5 4 3 2 1
Output: 
6
Explanation: 
Highest element of array a[] is 6.

Example 2:
Input:
5
1 2 3 4 5
Output:
5
Explanation: 
Highest element of array a[] is 5.
Your Task:
You don't need to read or print anything. Your task is to complete the function findPeakElement() which takes integer n, and the array a[] as the input parameters and returns the highest element of the array.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)

Constraints:
2 <= n <= 106
1 <= a[i] <= 106
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int s=0;
        int e=a.size()-1;
        int mid=(s+e)/2;
        
        if(e==0)return a[mid];
               
        while(s<=e)
        {
            if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
            {
                return a[mid];
            }
            else if(a[mid] > a[mid-1] && mid+1 > e)
            {
                return a[mid];
            }
            else if(a[mid] < a[mid+1])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            mid=(s+e)/2;
        }
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cout<<"Enter the testcases: ";
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}

