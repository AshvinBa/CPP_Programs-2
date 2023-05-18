#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int lastOccurence(int arr[],int n,int x)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    
    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int firstOccurence(int arr[],int n,int x)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    
    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int>ans1;
    int first=firstOccurence(arr,n,x);
    int last=lastOccurence(arr,n,x);
    // ans1.push_back(ans);
    return {first,last};
}
int main(){
    int arr[]={1,2,3,4,4,4,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=4;
    vector<int>res=find(arr,n,x);
    cout<<"Its first and last occurence is: ";
    for(auto i=res.begin();i!=res.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}