#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>&arr,int n,int x)
{
    int s=x+1;
    int e=n-1;
    while(s<=e)
    {
        swap(arr[s++],arr[e--]);
    }
}
int main(){
    int n;
    cout<<"Enter the limit of array: ";
    cin>>n;
    cout<<"Enter the number: ";
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nArray: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int x;
    cout<<"\nEnter the position for invert: ";      
    /*The number are reverse after one position of given*/
    cin>>x;

    reverse(arr,n,x);   
    cout<<"\nRevers array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}