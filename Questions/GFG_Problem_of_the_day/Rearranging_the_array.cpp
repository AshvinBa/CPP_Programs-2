#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print(int arr[],int n)
{
    cout<<"\nArray: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void Rearrange(int arr[],int n)
{
     
}


int main(){
    int n;
    int arr[]={-3,3,2,-2};
    n=sizeof(arr)/sizeof(arr[0]);
    Rearrange(arr,n);
return 0;
}

/*


void Rearrange(int arr[],int n)
{
    sort(arr,arr+n);
    
    int i=0;
    int j=i+1;
    while(j<n)
    {
        if(arr[i]<arr[j] && arr[i]>0 && arr[j]>0)
        {
            
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        i++;
        j++;
    }
    print(arr,n);
}

*/