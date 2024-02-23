/*
Maximum Index

Given an array a of n positive integers. The task is to find the maximum
of j - i subjected to the constraint of a[i] < a[j] and i < j.

Example 1:
Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.

Example 2:
Input:
n = 9
a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j])
thus giving the maximum difference of j - i which is 6(7-1).

Your Task:
The task is to complete the function maxIndexDiff() which finds and returns
maximum index difference. Printing the output will be handled by driver code. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 106
0 ≤ a[i] ≤ 109
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int>prefix(n),sufix(n);
        
        prefix[0]=a[0];
        sufix[n-1]=a[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=min(prefix[i-1],a[i]);
            sufix[n-i-1]=max(sufix[n-i],a[n-i-1]);
        }
        
        int i,j,ans;
        i=j=ans=0;
        
        while(j<n)
        {
            if(prefix[i]<=sufix[j])
            {
                ans=max(ans,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};

int main() 
{
    int T;
    //testcases
    cout<<"Enter the number of test cases: ";
    cin>>T;
    while(T--){
        int num;
        //size of array
        cout<<"Enter the size: ";
        cin>>num;
        int arr[num];
        cout<<"Enter the values: ";
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<"Answer: ";
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 