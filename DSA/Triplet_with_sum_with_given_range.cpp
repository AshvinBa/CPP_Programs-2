/*
Triplets with sum with given range

Given an array Arr[] of N distinct integers and a range from L to R, the task is to count the number of triplets having a sum in the range [L, R].

Example 1:
Input:
N = 4
Arr = {8 , 3, 5, 2}
L = 7, R = 11
Output: 1
Explaination: There is only one triplet {2, 3, 5}
having sum 10 in range [7, 11].

Example 2:
Input:
N = 5
Arr = {5, 1, 4, 3, 2}
L = 2, R = 7
Output: 2
Explaination: There two triplets having 
sum in range [2, 7] are {1,4,2} and {1,3,2}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countTriplets() which takes the array Arr[] and its size N and L and R as input parameters and returns the count.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int arr[], int N, int L, int R) 
    {
        sort(arr,arr+N);
        
        int a=make(arr,N,L-1);
        int b=make(arr,N,R);
        
        return b-a;
    }
    
    int make(int arr[],int n,int X)
    {
        int res=0;
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                
                if(sum>X)
                {
                    k--;
                }
                else
                {
                    res+=(k-j);
                    j++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
