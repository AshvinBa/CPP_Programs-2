/*
Smallest Positive missing number

You are given an array arr[] of N integers. The task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1.

Example 1:
Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.

Example 2:
Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {
        for(int i=0;i<n;i++)
        {
            int curr_index=arr[i]-1;
            while(arr[i]>0 && arr[i] <=n && arr[i] != arr[curr_index])
            {
                swap(arr[i],arr[curr_index]);
                curr_index=arr[i]-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    } 
};
/*
int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=0)
            {
                arr[i]=n+1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int index=abs(arr[i])-1;
            if(index<n)
            {
                arr[index] *= -1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
*/

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cout<<"Number of test cases: ";
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cout<<"Enter the size: ";
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        cout<<"Enter the values: ";
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 