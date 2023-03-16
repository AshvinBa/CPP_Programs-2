#include<iostream>
using namespace std;
int func(int arr[],int n)
{
    if(n==0)
    return 0;
    cout<<arr[0]<<" ";
    func(arr+1,n-1);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    func(arr,n);
return 0;
}