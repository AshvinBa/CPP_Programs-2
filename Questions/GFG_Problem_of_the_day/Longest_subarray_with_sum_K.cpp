/*
Longest Sub-Array with Sum K
Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

Examples:
Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.

Input : 
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
         unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == K) {
                maxLen = i + 1;
            }
            
            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - K]);
            }
            
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }
        
        return maxLen;
    } 

};

int main() {
	int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
	while(t--)
	{
	    int n, k;
        cout<<"Enter the size and value of K: ";
	    cin>> n >> k;
	    int a[n];
	    cout<<"Enter the values of array: ";
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
       cout<<"Answer: ";
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;   
	}	
	return 0;
}