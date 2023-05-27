// return the maximize sum of an array.
// return arr[i]*i

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximize(int arr[],int n)
{
    sort(arr,arr+n);
    long long int ans=0,i=0;
    long long int val=pow(10,9)+7;   //To return the large value using long long integer.
    for(;i<n;i++)
    {
        ans+=arr[i]*i;
    }
    return ans%val;
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\n Answer: "<<maximize(arr,n);
return 0;
}