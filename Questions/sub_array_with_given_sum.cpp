#include<bits/stdc++.h>
using namespace std;
vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int l=0;
        int r=0;
        int sum=arr[0];
        bool isfound=false;
        vector<int>ans;
        
        while(r<n)
        {
            if(sum==s)
            {
                isfound=true;
                break;
            }
            else if(sum<s)
            {
                r++;
                sum+=arr[r];
            }
            else
            {
                sum-=arr[l];
                l++;
            }
        }
        if(isfound)
        {
            ans.push_back(l+1);
            ans.push_back(r+1);
        }
        else
        {
            ans.push_back(-1);
        }
        return ans;
    }

//{ Driver Code Starts.

int main()
{
    vector<int>arr{1,2,3,4};
    int s=0;
    int n=4;
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
	return 0;
}