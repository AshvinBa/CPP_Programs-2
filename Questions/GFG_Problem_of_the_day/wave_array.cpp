//wave array.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void converToWave(vector<int>&arr,int n)
{
    for(int i=0;i<n-1;i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
}

int main(){
    vector<int>arr{1,2,3,4,5};
    int n=arr.size();
    converToWave(arr,n);
    cout<<"Answer: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}