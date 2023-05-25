#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cuts(vector<int>arr,int n,int k)
{
    int left[n];
    int right[n];

    left[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],arr[i]);
    }

    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=min(right[i+1],arr[i]);
    }

    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(left[i-1]+right[i]>=k)
        ans++;
    }
    return ans;
}

int main(){
    vector<int> arr{1,2,3,4,5};
    int n=arr.size();
    int k=5;
    cout<<"\nAnswer: "<<cuts(arr,n,k);
return 0;
}