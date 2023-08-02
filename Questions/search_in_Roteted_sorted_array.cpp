#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getpivot(vector<int> arr,int l,int h)
{
    int s=l;
    int e=h-1;
    int mid=(s+e)/2;

    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}

int binary_search(vector<int>arr,int s1,int e1,int key)
{
    int s=s1;
    int e=e1;
    int mid=(s+e)/2;

    while(s<=e)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            s=mid+1;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return -1;
}

int search(vector<int>arr,int s,int e,int key)
{
    int pivot=getpivot(arr,s,e);

    if(key>=arr[pivot] && key<=arr[e])
    {
        return binary_search(arr,pivot,e-1,key);
    }
    else
    {
        return binary_search(arr,0,pivot,key);
    }
}

int main(){
    int n;
    cout<<"Enter the limit of array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"\nThe Index of the Key is: "<<search(arr,0,n,key);
return 0;
}