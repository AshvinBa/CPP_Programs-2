#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSum(int a[],int n)
{
    sort(a,a+n);
    
    long int l=0,r=n-1;
    
    long int arr[n],k=0;
    
    while(l<r)
    {
        arr[k++]=a[l++];
        arr[k++]=a[r--];
    }
    
    if(n%2==1)
    {
        arr[k]=a[l];
    }
    
    int ans=0;
    for(int i=0;i<n-1;i++)
    ans+=abs(arr[i]-arr[i+1]);
    
    ans+=abs(arr[n-1]-arr[0]);
    
    
    return ans;

}

int main(){
    int arr[]={4,2,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nAnswer: "<<maxSum(arr,n);
return 0;
}