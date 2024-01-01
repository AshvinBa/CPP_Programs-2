/*
K-th Largest Sum Contiguous Subarray

You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements. In other words, over all subarrays, find the subarray with k-th largest sum and return its sum of elements.

Example 1:
Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.
 

Example 2:
Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the array Arr[] and its size N as inputs and returns the Kth largest subarray sum.

Expected Time Complexity: O(N2 * log K)
Expected Auxiliary Space: O(K)

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

/* optimized Approach 1*/
    int kthLargest(vector<int> &Arr,int N,int K){
        
        priority_queue<int,vector<int>,greater<int>>mini;
        
        for(int i=0;i<N;i++)
        {
            int sum=0;
            for(int J=i;J<N;J++)
            {
                sum+=Arr[J];
                
                if(mini.size()<K)
                {
                    mini.push(sum);
                }
                else
                {
                    if(mini.top()<sum)
                    {
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }
};
/*
Approach 2
        /*
        vector<int>vec;
        
        for(int i=0;i<N;i++)
        {
            int sum=0;
         
            for(int j=i;j<N;j++)
            {
                sum+=Arr[j];
                vec.push_back(sum);
            }
        }
        
        sort(vec.begin(),vec.end());
        
        return vec[vec.size()-K];
        */

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
























