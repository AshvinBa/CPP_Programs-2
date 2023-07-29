#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i;
    int right=2*i-1;

    if(left<=n && arr[left]>arr[large])
    {
        large=left;
    }
    if(right<=n && arr[right]>arr[large])
    {
        large=right;
    }
    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}


void heap_sort(int arr[],int n)
{
    int size=n;

    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}

void buid_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

void print(int arr[],int n)
{
    cout<<"\nThe array is: ";
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    cout<<"Enter the limit of array: ";
    cin>>n;

    int arr[n];
    cout<<"\nEnter the values: ";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    buid_heap(arr,n);
    print(arr,n);
    heap_sort(arr,n);
    print(arr,n);
return 0;
}

















