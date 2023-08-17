#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Approach - 2.

bool findPair(int arr[], int size, int n)
{
    bool ans=false;
    unordered_map<int,int>mp;
    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0;i<size;i++)
    {
        int y=arr[i]+n;
        if(mp[y])
        {
            ans=true;
            break;
        }
    }
    return ans;
}

//Approach - 1.
/*
bool findPair(int arr[], int size, int n){
// TC=O(nlog(n))    
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(abs(arr[i]-arr[j])==n)
            {
                return true;
            }
        }
    }
    return false;
}
*/
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
    cout<<"Enter the digit: ";
    cin>>k;
    if(findPair(arr,n,k))
    {
        cout<<"Yes! It's Present.";
    }
    else
    {
        cout<<"No! Not Present.";
    }
return 0;
}