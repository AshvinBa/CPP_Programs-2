/*
Smaller Sum

You can earn more Geekbits by participating in GFG Weekly Coding Contest  

You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:

Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.
*/

/*
Example 2:

Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<long long> smallerSum(int n,vector<int> &arr)
{
    map<ll,ll>mp;
    unordered_map<ll,ll>Presum;
    
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    ll prevsum=0;
    
    for(auto it:mp)
    {
        Presum[it.first]=prevsum;
        prevsum+=it.second*it.first;
    }
    vector<ll>ans;
    for(int i=0;i<n;i++)
    {
        ll currans=Presum[arr[i]];
        ans.push_back(currans);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<ll>res=smallerSum(n,vec);
    for(auto i=res.begin();i!=res.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}