#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int arr[],int n)
{
    int g=0;
    for(int i=0;i<n;i++)
    {
        g=__gcd(g,arr[i]);
    }
    return g;
}
int main(){
    int n=4;
    int arr[]={1,2,3,4};
    cout<<"Answer: "<<gcd(arr,n);
return 0;
}