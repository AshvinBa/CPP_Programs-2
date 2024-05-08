/*
Find triplets with zero sum.

Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
Note: Return 1, if there is at least one triplet following the condition else return 0.

Example 1:
Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.

Example 2:
Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists. 

Your Task:
You don't need to read input or print anything. Your task is to complete the boolean function 
findTriplets() which takes the array arr[] and the size of the array (n) as inputs and print 1 
if the function returns true else print 0 if the function returns false. 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 104
-106 <= Ai <= 106
*/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(arr[i]+arr[j]+arr[k]==0)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
	cin>>t;
	while(t--){
    	int n;
        cout<<"Enter the size: ";
    	cin>>n;
    	int arr[n]={0};
        cout<<"Enter the valeus: ";
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        cout<<"Answer: ";
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}