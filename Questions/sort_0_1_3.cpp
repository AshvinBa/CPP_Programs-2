#include<iostream>
using namespace std;

int recursive_array(int arr[],int n)
{
    if(n==0)
    return 0;

    cout<<arr[0]<<" ";

    return recursive_array(arr+1,n-1);
}

int sortArr(int arr[],int n)
{
    int i=0,cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        switch(arr[i])
        {
            case 0:
            cnt0++;
            break;

            case 1:
            cnt1++;
            break;

            case 2:
            cnt2++;
            break;
        }
    }
    i=0;

    while(cnt0>0)
    {
        arr[i++]=0;
        cnt0--;
    }

    while(cnt1>0)
    {
        arr[i++]=1;
        cnt1--;
    }

    while(cnt2>0)
    {
        arr[i++]=2;
        cnt2--;
    }
    recursive_array(arr,n);
}
int main(){
    int arr[]={0,0,1,0,2,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortArr(arr,n);
return 0;
}