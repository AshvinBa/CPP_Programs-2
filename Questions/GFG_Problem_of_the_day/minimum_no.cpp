#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mini_NUM(vector<int>&arr,int n)
{
    int i=0,j=i+1;
    // cout<<n;
    int ans=0;
    while(i<n && j<n)
    {
        if(arr[i]<=arr[j])
        {
            ans=(arr[i]-arr[j]);
            arr[i]=abs(ans);
            i++;
        }
        else
        {
            arr[i]=abs(arr[i]-arr[j]);
            j--;
        }
    }
    for(int i1=0;i1<n;i1++)
    {
        cout<<arr[i1]<<" ";
    }

}
int main(){
    vector<int>arr{3,2,4};
    int n=arr.size();
    mini_NUM(arr,n);
return 0;
}