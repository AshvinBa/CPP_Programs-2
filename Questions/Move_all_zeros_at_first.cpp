#include<iostream>
using namespace std;

void pushZerosAtStart(int arr[],int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(arr[i]==0 and i<j)
        {
            i++;
        }
        while(arr[j]==1 and i<j)
        {
            j--;
        }
        if(arr[i]==1 and arr[j]==0 and i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}

int main(){
    int arr[]={1,1,1,1,0,0,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    pushZerosAtStart(arr,n);
    cout<<"\nAnswer: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}