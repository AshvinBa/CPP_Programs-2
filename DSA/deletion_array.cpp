#include<iostream>
using namespace std;
int deletion(int arr[],int index,int n)
{
    for(int i=index;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
}
int display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the Size of array: ";
    cin>>n;
    int index,arr[100];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter at which index want to deleat: ";
    cin>>index;
    deletion(arr,index,n);
    n-=1;
    display(arr,n);
return 0;
}