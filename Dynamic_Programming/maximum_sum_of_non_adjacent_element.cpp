/*
Max Sum without Adjacents
Given an array Arr of size N containing positive integers. Find the maximum sum of a any possible subsequence 
such that no two numbers in the subsequence should be adjacent in Arr.

Example 1:
Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

Example 2:
Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous subsequence with maximum
sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which 
takes the array of integers Arr and N as parameters and returns an the maximum sum possible of any valid subsequence.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arri ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    int prev2=0;
	    int prev1=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        int incl=prev2 + arr[i];
	        int excl=prev1 + 0;
	        
	        int ans=max(incl,excl);
	        prev2=prev1;
	        prev1=ans;
	    }
	    return prev1;
	}
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Enter the size: ";
        cin >> n;
        int arr[n];
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout<<"The maximum values: ";
        cout << ans << "\n";
    }
    return 0;
}