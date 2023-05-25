#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Approach 1-
/*
int majority(int arr[],int n)
{
    int ele=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            ele=arr[i];
        }
        if(ele==arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(ele==arr[i])
        {
            cnt++;
        }
    }
    if(cnt>n/2)
    {
        return ele;
    }
    return -1;
}
*/

//Approach 2-

int majority(int arr[],int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second>n/2)
        {
            return it.first;
        }
    }
    return -1;
}


int main(){
    int arr[]={1,2,4,4,4,4};
    int n=6;
    cout<<"\nAnswer: "<<majority(arr,n);
return 0;
}