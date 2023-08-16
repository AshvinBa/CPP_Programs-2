#include<iostream>
using namespace std;

void pushZerosAtStart(int arr[],int n)
{
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    int i=0;
    while(i<n)
    {
        switch(arr[i])
        {
            case 0:
            {
                cnt0++;
            }
            break;
            case 1:
            {
                cnt1++;
            }
            break;
            case 2:
            {
                cnt2++;
            }
            break;
        }
        i++;
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
}

int main(){
    int arr[]={2,1,2,1,0,2,1,0,2,1,2,0,1,2,0,1,1,1,1,0,2,2,2,0,0,1};
     
    int n=sizeof(arr)/sizeof(arr[0]);
    pushZerosAtStart(arr,n);
    cout<<"\nAnswer: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}