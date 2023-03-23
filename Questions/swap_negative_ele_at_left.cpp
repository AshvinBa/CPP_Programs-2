/*
#include<iostream>
using namespace std;
int negative_ele(int arr[],int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        if(arr[s]>0 and arr[e]<0)
        {
            swap(arr[s],arr[e]);            
        }
        else if(arr[s]<0)
        {
            s++;
        }
        else if(arr[e]>0)
        {
            e--;
        }
    }
}
int main(){
    int arr[]={-1,10,12,13,14,15,14-3,-5,4,2,-1,5,3,6,-4,-8,-9,-10,-7};
    int n=sizeof(arr)/sizeof(arr[0]);
    negative_ele(arr,n);
    cout<<"\nArray:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}

*/

