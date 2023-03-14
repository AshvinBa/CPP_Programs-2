#include<iostream>
using namespace std;
int pivote_ele(int arr[],int n)
{
    int s=0,e=n-1;
    int mid=(s+e)/2;
    int ans=-1;

    while(s<=e)
    {
        if(arr[mid]>arr[0])
        {
            ans=arr[mid];
            s=mid+1;
        }        
        else
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}
int main(){
    int arr[]={2,3,10,17,18,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nThe Pivote Element is: "<<pivote_ele(arr,n);
return 0;
}