#include<iostream>
using namespace std;
int func(int arr[],int s,int e,int k)
{
    int mid=(s+e)/2;

    if(s>e)
    return -1;

    if(arr[mid]==k)
    {
        return mid;
    }
    else if(arr[mid]<k)
    {
        return func(arr,s=mid+1,e,k);
    }
    else
    {
        return func(arr,s,e=mid-1,k);
    }
}
int main(){
    int arr[]={11,22,33,44,55,66};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=n-1;
    int k;
    cout<<"Enter the number: ";
    cin>>k;
    cout<<func(arr,s,e,k);
return 0;
}