#include<iostream>
using namespace std;
int sorting_algo(int arr[],int n)
{
    int cnt0=0,cnt1=0,cnt2=0;
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

            default:
            cout<<"No its not valid.";
        }
    }

    int k=0;
    while(cnt0>0)
    {
        arr[k++]=0;
        cnt0--;
    }
    while(cnt1>0)
    {
        arr[k++]=1;
        cnt1--;
    }
    while(cnt2>0)
    {
        arr[k++]=2;
        cnt2--;
    }
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10000];
    int n;
    cout<<"Enter the limits: ";
    cin>>n;
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sorting_algo(arr,n);    
return 0;
}