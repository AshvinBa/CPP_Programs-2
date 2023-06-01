#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minSwaps(vector<int>&arr)
	{
	    int n=arr.size();
	    vector<pair<int,int > >v(n);
	    for(int i=0;i<n;i++)
	    {
	        v[i]={arr[i],i};
	    }
	    sort(v.begin(),v.end());
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i)
	        continue;
	        else
	        {
	            cnt++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return cnt;
	}

int main(){
    vector<int>arr{2,8,5,4};
    int n=arr.size();
    cout<<"\nThe Number of Swap: ";
    cout<<minSwaps(arr);
return 0;
}