/*
Largest subarray with 0 sum

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxLen(vector<int>&arr, int n)
    {   
        int ans=0;
        int sum=0;
        
        unordered_map<int,int> mp;
        
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!= mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return ans;
    }

int main(){
    vector<int> arr{15,-2,2,-8,1,7,10,23};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int n=arr.size();
    cout<<"Answer: "<<maxLen(arr,n);
return 0;
}