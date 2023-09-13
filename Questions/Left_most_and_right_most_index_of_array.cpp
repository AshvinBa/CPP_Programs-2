/*
Left most and right most index
Given a sorted array with possibly duplicate elements. The task is to find indexes of first and last occurrences of an element X in the given array.
Note: If the element is not present in the array return {-1,-1} as pair.
Example 1:
Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}
X = 5
Output:
2 5
Explanation:
Index of first occurrence of 5 is 2
and index of last occurrence of 5 is 5.

Example 2:
Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 7, 123, 125}
X = 7
Output:
6 6
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function indexes() which takes the array v[] and an integer X as inputs and returns  the first and last occurrence of the element X. If the element is not present in the array return {-1,-1} as pair.
Can you solve the problem in expected time complexity?
Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 105
1 ≤ v[i], X ≤ 1018

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    int first1(vector<long long>v,long long x,int n)
    {
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(x==v[mid])
            {
                ans=mid;
                e=mid-1;
            }
            else if(x>v[mid])
            {
                s=mid+1;
            }
            else if(x<v[mid])
            {
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    int second1(vector<long long>v,long long x,int n)
    {
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(x==v[mid])
            {
                ans=mid;
                s=mid+1;
            }
            else if(x<v[mid])
            {
                e=mid-1;
            }
            else if(x>v[mid])
            {
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n=v.size();
        pair<long,long>p;
        p.first=first1(v,x,n);
        p.second=second1(v,x,n);
        return p;
    }
int main()
 {
    
        long long n, k;
        vector<long long>v;
        cout<<"Enter the limit of array: ";
        cin>>n;
        cout<<"Enter the values: ";
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cout<<"Digit for search: ";
        cin>>x;
        pair<long,long> pair = indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;
	return 0;
}
