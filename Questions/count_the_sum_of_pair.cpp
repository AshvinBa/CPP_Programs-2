#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getPairs(int arr[],int n,int k)
{
    int ans=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int b=k-arr[i];
        if(m[b])
        {
            ans++;
        }
        m[arr[i]]++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value: ";
    cin>>k;
    cout<<"The number of count is: "<<getPairs(arr,n,k);
return 0;
}