#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the values: ";
    cin>>n;
    int arr[1000];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;
    int k=n-1;
    int result[1000];

    while(i<j and k>=0)
    {
        if(abs(arr[i])>abs(arr[j]))
        {
            result[k]=arr[i]*arr[i];
            i++;
            k--;
        }
        else
        {
            result[k]=arr[j]*arr[j];
            j--;
            k--;
        }
    }

    cout<<"\nThe array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }
return 0;
}